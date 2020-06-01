//
// Created by rocki on 5/31/2020.
//

#include "FrequencyTable.h"
#include <algorithm>

int FrequencyTable::Find(const FrequencyElement* key) {
    for (size_t i = 0; i < _data.size(); i++) {
        if (*_data[i] == *key) {
            return i;
        }
    }

    return -1;
}

void FrequencyTable::InsertElement(FrequencyElement* element) {
    int search = Find(element);

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
}

FrequencyTable::~FrequencyTable() {
    for (size_t i = 0; i < _data.size(); i++) {
        delete _data[i];
    }
}

void FrequencyTable::Sort() {
    for (size_t i = 1; i < _data.size(); ++i) {
        size_t j = i;
        // Insert numbers[i] into sorted part
        // stopping once numbers[i] in correct position
        while (j > 0 && *_data[j] > *_data[j - 1]) {

            // Swap numbers[j] and numbers[j - 1]
            FrequencyElement* temp = _data[j];
            _data[j] = _data[j - 1];
            _data[j - 1] = temp;
            --j;
        }
    }
}

void FrequencyTable::InsertElementSorted(FrequencyElement* element) {
    int search = Find(element);

    if (search != -1) {
        _data[search]->IncreaseCount();
        delete element;
    }
    else {
        _data.push_back(element);
    }

    Sort();
}

