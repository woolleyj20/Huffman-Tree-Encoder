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
    int BinaryFind(const string& key);
    FrequencyElement* ReturnElement(int& position);
    void InsertElement(FrequencyElement* element);
    void InsertElementSorted(FrequencyElement* element);
    FrequencyElement* RemoveElement();
    void Sort();
    void SortChar();
    string PrintTableWithCodes();
    string PrintTableWithFrequencies();
    void WriteEncodedFile(istream& input, ostream& output);
};


#endif //HUFFMAN_WOOLLEYJ20_FREQUENCYTABLE_H
