//
// Created by rocki on 6/1/2020.
//

#include "HuffmanTree.h"
#include <list>

//Helper Functions
int HuffmanListSearch(string& data, vector<HuffmanTree*> list) {
    for (size_t i = 0; i < list.size(); i++) {
        if (data == list[i]->GetData()) {
            return i;
        }
    }

    return -1;
}

HuffmanTree* PullForTree(FrequencyTable* table, vector<HuffmanTree*> vector) {
    FrequencyElement* element = table->RemoveElement();
    string label = element->GetLabel();
    size_t count = element->GetCount();
    delete element;
    int search = HuffmanListSearch(label, vector);

    HuffmanTree* tree = nullptr;

    if (search != -1) {
        tree = vector[search];
    }
    else {
        tree = new HuffmanTree(label, count);
        vector.push_back(tree);
    }

    return tree;
}



//Member Functions
void HuffmanTree::MergeTrees(HuffmanTree* a, HuffmanTree* b) {
    _leftChild = a;
    _rightChild = b;

    string newData = _leftChild->_data + _rightChild->_data;
    _data = newData;

    _count = _leftChild->_count + _rightChild->_count;
}

HuffmanTree::HuffmanTree(string& data, size_t& count) : _data(data), _count(count), _leftChild(nullptr), _rightChild(nullptr) {}

HuffmanTree::HuffmanTree() : _data(""), _count(0), _leftChild(nullptr), _rightChild(nullptr) {}

HuffmanTree::HuffmanTree(FrequencyTable* toRead) {
    vector<HuffmanTree*> holding;

    HuffmanTree* neo = nullptr;

    while (toRead->Size() > 2) {
        HuffmanTree* first = PullForTree(toRead, holding);

        HuffmanTree* second = PullForTree(toRead, holding);

        neo = new HuffmanTree();
        neo->MergeTrees(first, second);

        holding.push_back(neo);

        FrequencyElement* neoEl = new FrequencyElement(neo->_data, neo->_count);
        toRead->InsertElementSorted(neoEl);
    }

    HuffmanTree* first = PullForTree(toRead, holding);

    HuffmanTree* second = PullForTree(toRead, holding);

    MergeTrees(first, second);

    FrequencyElement* neoEl = new FrequencyElement(_data, _count);
    toRead->InsertElementSorted(neoEl);
}

string HuffmanTree::GetData() {
    return _data;
}

void HuffmanTree::SetCodes(FrequencyTable* table) {
    for (size_t i = 0; i < table->Size(); i++) {
        FrequencyElement* toSet = table->ReturnElement(i);
        PullCode(toSet);
    }
}

void HuffmanTree::PullCode(FrequencyElement* element){
    string code = "";
    HuffmanTree* track = this;

    bool dataFound = false;

    while (!dataFound) {
        if (track->_leftChild->_data.find_first_of(element->GetLabel()) != string::npos) {
            track = track->_leftChild;
            code += "1";
        }
        else {
            track = track->_rightChild;
            code += "0";
        }
        if (track->_data == element->GetLabel()) {
            dataFound = true;
        }
    }

    element->SetCode(code);
}

HuffmanTree::~HuffmanTree() {
   Clear();
}

void HuffmanTree::Clear() {
    if (_leftChild) {
        _leftChild->Clear();
        delete _leftChild;
        _leftChild = nullptr;
    }
    if (_rightChild) {
        _rightChild->Clear();
        delete _rightChild;
        _rightChild = nullptr;
    }

}
