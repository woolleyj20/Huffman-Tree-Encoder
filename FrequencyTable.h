//
// Created by rocki on 5/31/2020.
//

#ifndef HUFFMAN_WOOLLEYJ20_FREQUENCYTABLE_H
#define HUFFMAN_WOOLLEYJ20_FREQUENCYTABLE_H

#include "FrequencyElement.h"
#include <vector>

using namespace std;


class FrequencyTable {
    vector<FrequencyElement*> _data;
public:
    ~FrequencyTable();
    int Find(const FrequencyElement* key);
    void InsertElement(FrequencyElement* element);
    void InsertElementSorted(FrequencyElement* element);
    FrequencyElement* RemoveElement();
    void Sort();
};


#endif //HUFFMAN_WOOLLEYJ20_FREQUENCYTABLE_H
