//
// Created by rocki on 6/1/2020.
//

#ifndef HUFFMAN_WOOLLEYJ20_HUFFMANTREE_H
#define HUFFMAN_WOOLLEYJ20_HUFFMANTREE_H

#include <string>
#include "FrequencyTable.h"


using namespace std;

class HuffmanTree {
    string _data;
    size_t _count;
    HuffmanTree* _leftChild;
    HuffmanTree* _rightChild;


    void MergeTrees(HuffmanTree* a, HuffmanTree* b);
    HuffmanTree();

    void Clear();


    void PullCode(FrequencyElement* element);
public:
    HuffmanTree(FrequencyTable* toRead);
    ~HuffmanTree();
    void SetCodes(FrequencyTable* table);
    HuffmanTree(string& data, size_t& count);
    string GetData();



};


#endif //HUFFMAN_WOOLLEYJ20_HUFFMANTREE_H
