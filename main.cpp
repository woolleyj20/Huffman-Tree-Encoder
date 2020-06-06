//
// Created by rocki on 5/30/2020.
//

#include "FrequencyElement.h"
#include "FrequencyTable.h"
#include "HuffmanTree.h"

#include <string>
#include <list>
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;



int main(int argc, char* argv[]) {
    ifstream input;
    FrequencyTable* table = new FrequencyTable();



//    input.open(argv[1]);

    cout << "Enter file in: " << endl;
    string in;
    getline(cin, in);

    input.open(in);

    if (!input.is_open()) {
        cout << "Could not open file: " << in << endl;
    }
    else {
        while (!input.eof()) {
            char character = input.get();
            string label(1, character);

            if (label == "\377") {
                break;
            }

            FrequencyElement* element = new FrequencyElement(label);
            table->InsertElement(element);
        }
    }

    input.close();

    table->Sort();

    FrequencyTable* copy = new FrequencyTable(table);

    HuffmanTree* tree = new HuffmanTree(copy);

    tree->SetCodes(table);

    cout << table->PrintTableWithCodes() << endl;

    ofstream output;

//    output.open(argv[2]);
//    input.open(argv[1]);

    cout << "Enter file out: " << endl;
    string out;
    getline(cin, out);

    output.open(out);

    input.open(in);




    if (!output.is_open()) {
        cout << "Could not open output file: " << out << endl;
    }
    else {
        if (!input.is_open()) {
            cout << "Could not open in file: " << in << endl;
        }
        else {
            table->SortChar();
            table->WriteEncodedFile(input, output);
        }
    }

    input.close();
    output.close();

    delete table;
    delete copy;
    delete tree;
}



