//
// Created by rocki on 5/31/2020.
//

#include "FrequencyTable.h"
#include <algorithm>
#include <sstream>

using namespace std;

//Helper Functions
bool FrequencyElementCompare(const FrequencyElement* lhs, const FrequencyElement* rhs) {
    if (lhs->GetCount() == rhs->GetCount()) {
        return (lhs->GetLabel() > rhs->GetLabel());
    }
    else {
        return (lhs->GetCount() > rhs->GetCount());
    }
}

bool FrequencyElementCompareChar(const FrequencyElement* lhs, const FrequencyElement* rhs) {
    return lhs->GetLabel() < rhs->GetLabel();
}

//Member Functions

int FrequencyTable::Find(const string& key) {
    for (size_t i = 0; i < _data.size(); i++) {
        if (_data[i]->GetLabel() == key) {
            return i;
        }
    }

    return -1;
}

void FrequencyTable::InsertElement(FrequencyElement* element) {
    int search = Find(element->GetLabel());

    if (search != -1) {
        _data[search]->IncreaseCount();
        delete element;
    }
    else {
        _data.push_back(element);
    }
}

FrequencyElement* FrequencyTable::RemoveElement() {
    FrequencyElement* returned = _data[_data.size() - 1];
    _data.pop_back();

    return returned;
}

FrequencyTable::~FrequencyTable() {
    for (size_t i = 0; i < _data.size(); i++) {
        delete _data[i];
    }
}

void FrequencyTable::Sort() {
//    for (size_t i = 1; i < _data.size(); ++i) {
//        size_t j = i;
//        // Insert numbers[i] into sorted part
//        // stopping once numbers[i] in correct position
//        while (j > 0 && *_data[j] > *_data[j - 1]) {
//
//            // Swap numbers[j] and numbers[j - 1]
//            FrequencyElement* temp = _data[j];
//            _data[j] = _data[j - 1];
//            _data[j - 1] = temp;
//            --j;
//        }
//    }

    sort(_data.begin(), _data.end(), FrequencyElementCompare);
}

void FrequencyTable::InsertElementSorted(FrequencyElement* element) {
    int search = Find(element->GetLabel());

    if (search != -1) {
        _data[search]->IncreaseCount();
        delete element;
    }
    else {
        _data.push_back(element);
    }

    Sort();
}

size_t FrequencyTable::Size() {
    return _data.size();
}

FrequencyTable::FrequencyTable() {
    vector<FrequencyElement*> temp;
    _data = temp;
}

FrequencyTable::FrequencyTable(FrequencyTable* table) {
    vector<FrequencyElement*> newData;
    for (size_t i = 0; i < table->_data.size(); i++) {
        FrequencyElement* neo = new FrequencyElement(table->_data[i]->GetLabel(), table->_data[i]->GetCount());
        newData.push_back(neo);
    }

    _data = newData;
}

FrequencyElement* FrequencyTable::ReturnElement(int& position) {
    if (position < 0) {
        return nullptr;
    }
    return _data[position];
}

string FrequencyTable::PrintTableWithCodes() {
    stringstream retVal;

    for (size_t i = 0; i < _data.size(); i++) {
        retVal << "{key: "
        << _data[i]->GetLabel()
        << ", code: "
        << _data[i]->GetCode()
        << "}" << endl;
    }

    return retVal.str();
}

string FrequencyTable::PrintTableWithFrequencies() {
    stringstream retVal;

    for (size_t i = 0; i < _data.size(); i++) {
        retVal << "{key: "
               << _data[i]->GetLabel()
               << ", frequency: "
               << _data[i]->GetCount()
               << "}" << endl;
    }

    return retVal.str();
}

void FrequencyTable::WriteEncodedFile(istream& input, ostream& output) {
    while (!input.eof()) {
        char character = input.get();
        string label(1, character);

        if (label == "\n") {
            label = "CR";
        }
        if (label == "\377") {
            break;
        }

        int searchResult = BinaryFind(label);
        FrequencyElement* searchElement = ReturnElement(searchResult);
        output << searchElement->GetCode();
    }
}

void FrequencyTable::SortChar() {
    sort(_data.begin(), _data.end(), FrequencyElementCompareChar);
}

int FrequencyTable::BinaryFind(const string& key) {
    if (_data.size() == 0) {
        return false;
    }

    int start = 0;
    int end = _data.size() - 1;
    int mid = (start + end) / 2;
    FrequencyElement* search = nullptr;

    while (end >= start) {
        search = ReturnElement(mid);
        if (search->GetLabel() == key) {
            return mid;
        }
        else if (search->GetLabel() > key) {
            end = mid - 1;
            mid = (start + end) / 2;
        }
        else if (search->GetLabel() < key) {
            start = mid + 1;
            mid = (start + end) / 2;
        }
    }

    return start;
}





