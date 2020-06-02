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
    FrequencyTable();
    ~FrequencyTable();
    FrequencyTable(FrequencyTable* table);
    size_t Size();
    int Find(const string& key);
    FrequencyElement* ReturnElement(size_t& position);
    void InsertElement(FrequencyElement* element);
    void InsertElementSorted(FrequencyElement* element);
    FrequencyElement* RemoveElement();
    void Sort();
    string PrintTableWithCodes();
    string PrintTableWithFrequencies();
    void WriteEncodedFile(ifstream& input, ofstream& output);
};


#endif //HUFFMAN_WOOLLEYJ20_FREQUENCYTABLE_H
