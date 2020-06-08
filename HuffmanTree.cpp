/*
 * Filename: HuffmanTree.cpp
 * Description: Implementation of HuffmanTree
 * Author: Jason Woolley
 * Date: 6/8/2020
 * Course: Data Structures II
 */

#include "HuffmanTree.h"
#include <list>

//Helper Functions
int HuffmanListSearch(string& data, vector<HuffmanTree*> list) {
    //In the implementation of building the tree, a list of nodes (other trees) are kept.  This function is used to search it

    //It is basic linear search

    for (size_t i = 0; i < list.size(); i++) {
        if (data == list[i]->GetData()) {
            return i;
        }
    }

    return -1;
}


HuffmanTree* PullForTree(FrequencyTable* table, vector<HuffmanTree*> vector) {
    //Similar to the other helper function, this takes in the temp list of HuffmanTrees so that it doesn't create a new one if it's already there.

    //Pulls the element from the table, gets its information, then deletes the resource
    FrequencyElement* element = table->RemoveElement();
    string label = element->GetLabel();
    size_t count = element->GetCount();
    delete element;

    //Checks if the label is already in the tree somewhere (this will happen when it's a merged part)
    int search = HuffmanListSearch(label, vector);


    HuffmanTree* tree = nullptr;

    //If it's an already existing element, just point to the element for using.  If it's fresh, make a new huffman tree and also put that in the vector
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
    //When merging trees to build, have the left and right children point to the parameter trees

    _leftChild = a;
    _rightChild = b;

    //Merge the data
    string newData = _leftChild->_data + _rightChild->_data;
    _data = newData;

    //Merge the counts
    _count = _leftChild->_count + _rightChild->_count;
}

//Initialize values with data and count
HuffmanTree::HuffmanTree(string& data, size_t& count) : _data(data), _count(count), _leftChild(nullptr), _rightChild(nullptr) {}

//Initialize a default tree with default values
HuffmanTree::HuffmanTree() : _data(""), _count(0), _leftChild(nullptr), _rightChild(nullptr) {}

HuffmanTree::HuffmanTree(FrequencyTable* toRead) {
    //Make a vector for holding list of tree elements made
    vector<HuffmanTree*> holding;

    HuffmanTree* neo = nullptr;

    //While the table has more than two elements left, pull the bottom two and merge them
    while (toRead->Size() > 2) {
        //Pull first a second
        HuffmanTree* first = PullForTree(toRead, holding);

        HuffmanTree* second = PullForTree(toRead, holding);

        //Make a default tree to merge
        neo = new HuffmanTree();
        neo->MergeTrees(first, second);

        //Put the merge into the vector
        holding.push_back(neo);

        //Re-insert the new element into the table making sure it is sorted
        FrequencyElement* neoEl = new FrequencyElement(neo->_data, neo->_count);
        toRead->InsertElementSorted(neoEl);
    }

    //On the last time, no need to put things into the vector
    HuffmanTree* first = PullForTree(toRead, holding);

    HuffmanTree* second = PullForTree(toRead, holding);

    MergeTrees(first, second);

    FrequencyElement* neoEl = new FrequencyElement(_data, _count);
    toRead->InsertElementSorted(neoEl);
}

string HuffmanTree::GetData() {
    //Accessor for the data outside of member functions
    return _data;
}


void HuffmanTree::SetCodes(FrequencyTable* table) {
    //Traverses all elements of the table, and pulls their codes

    for (size_t i = 0; i < table->Size(); i++) {
        FrequencyElement* toSet = table->ReturnElement(i);
        PullCode(toSet);
    }
}

void HuffmanTree::PullCode(FrequencyElement* element){
    //Make needed variables
    string code = "";
    HuffmanTree* track = this;

    bool dataFound = false;


    //Using find_first_of, look for which child of the head contains the element needed.  Keep doing this till exactly that element is found
    //0s and 1s are added to the code as it traverses
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

    //Set the code
    element->SetCode(code);
}

HuffmanTree::~HuffmanTree() {
    //Destructor calls clear method.  Head is cleared by this
    Clear();
}

void HuffmanTree::Clear() {
    //Uses postorder traversal to clear all nodes in the tree besides the head
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
