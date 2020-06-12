/*
 * Filename: FrequencyTable.cpp
 * Description: Implementation of FrequencyTable
 * Author: Jason Woolley
 * Date: 6/8/2020
 * Course: Data Structures II
 */

#include "FrequencyTable.h"
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

//Helper Functions
bool FrequencyElementCompare(const FrequencyElement* lhs, const FrequencyElement* rhs) {
    //This comparison is used for the sort method.  It compares the frequency of the elements first, then by name if the frequencies are the same

    if (lhs->GetCount() == rhs->GetCount()) {
        return (lhs->GetLabel() > rhs->GetLabel());
    }
    else {
        return (lhs->GetCount() > rhs->GetCount());
    }
}

//Member Functions

int FrequencyTable::Find(const string& key) {
    //Basic linear searching for the key in each element

    for (size_t i = 0; i < _data.size(); i++) {
        if (_data[i]->GetLabel() == key) {
            return i;
        }
    }

    return -1;
}

void FrequencyTable::InsertElement(FrequencyElement* element) {
    //First search to see if the element is already there.
    int search = Find(element->GetLabel());

    //If it is there, just increase the count.  If it isn't put a new element in the table.
    if (search != -1) {
        _data[search]->IncreaseCount();
        delete element;
    }
    else {
        _data.push_back(element);
    }
}

FrequencyElement* FrequencyTable::RemoveElement() {
    //This function in only ever used when building the tree.  You only even remove from the bottom (or end), so it's built to only remove the last one.

    FrequencyElement* returned = _data[_data.size() - 1];
    _data.pop_back();

    return returned;
}

FrequencyTable::~FrequencyTable() {
    //Destructor needs to properly delete all of the data inside.

    for (size_t i = 0; i < _data.size(); i++) {
        delete _data[i];
    }
}

void FrequencyTable::Sort() {
    //Calls the sort method on the full list using the helper function to compare

    sort(_data.begin(), _data.end(), FrequencyElementCompare);
}

void FrequencyTable::InsertElementSorted(FrequencyElement* element) {
    //Identical to InsertElement but sorts the list after inserted.  This is used while building the tree

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
    //Return the size for when it's needed outside of a member function
    return _data.size();
}

FrequencyTable::FrequencyTable() {
   //Default constructor makes sure a vector is created.

    vector<FrequencyElement*> temp;
    _data = temp;
}

FrequencyTable::FrequencyTable(FrequencyTable* table) {
   //Copy constructor.  Needed for keeping a copy unaltered while the tree is being built so that the codes can all be pulled later

    vector<FrequencyElement*> newData;
    for (size_t i = 0; i < table->_data.size(); i++) {
        FrequencyElement* neo = new FrequencyElement(table->_data[i]->GetLabel(), table->_data[i]->GetCount());
        newData.push_back(neo);
    }

    _data = newData;
}

FrequencyElement* FrequencyTable::ReturnElement(size_t& position) {
   //An accessor function for pulling elements from the list

    return _data[position];
}

string FrequencyTable::PrintTableWithCodes() {
    //Print the table showing all codes

    stringstream retVal;

    for (size_t i = 0; i < _data.size() - 1; i++) {
        retVal << "{key: ";

        //The string of "\n" is printed as "CR" so that it isn't actually a newline character
        if (_data[i]->GetLabel() == "\n") {
            retVal << "CR";
        }

        //The string of "\r" is printed as "LF" so that it isn't actually a newline character
        else if (_data[i]->GetLabel() == "\r") {
            retVal << "LF";
        }
        else {
            retVal << " " << _data[i]->GetLabel();
        }
        retVal << ", code: "
        << _data[i]->GetCode()
        << "}" << endl;
    }

    retVal << "{key: ";

    //The string of "\n" is printed as "CR" so that it isn't actually a newline character
    if (_data[_data.size() - 1]->GetLabel() == "\n") {
        retVal << "CR";
    }

        //The string of "\r" is printed as "LF" so that it isn't actually a newline character
    else if (_data[_data.size() - 1]->GetLabel() == "\r") {
        retVal << "LF";
    }
    else {
        retVal << " " << _data[_data.size() - 1]->GetLabel();
    }
    retVal << ", code: "
           << _data[_data.size() - 1]->GetCode()
           << "}";

    return retVal.str();
}

void FrequencyTable::WriteEncodedFile(istream& input, ostream& output) {
    //Takes inputs to convert from text to encoded using the called table

    while (!input.eof()) {
        char character = input.get();
        string label(1, character);

        if (label == "\377") {
            break;
        }

        //Find the element in the table that matches it, then inputs into the output its code
        size_t searchResult = Find(label);
        FrequencyElement* searchElement = ReturnElement(searchResult);
        output << searchElement->GetCode();
    }
}





