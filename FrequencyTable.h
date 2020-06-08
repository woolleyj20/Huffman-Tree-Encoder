/*
 * Filename: FrequencyTable.h
 * Description: Declaration of FrequencyTable, a class for holding the characters of a file including their frequencies and codes.  Functions help
 * manage the table easier
 * Author: Jason Woolley
 * Date: 6/8/2020
 * Course: Data Structures II
 */

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
    void WriteEncodedFile(istream& input, ostream& output);
};


#endif //HUFFMAN_WOOLLEYJ20_FREQUENCYTABLE_H
