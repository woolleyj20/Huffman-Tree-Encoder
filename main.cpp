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

int main() {
    ifstream stream;
    FrequencyTable* table = new FrequencyTable();

    cout << "Please input file name: " << endl;
    string file;
    getline(cin, file);

    stream.open(file);

    if (!stream.is_open()) {
        cout << "Could not open file: " << file << endl;
    }
    else {
        while (!stream.eof()) {
            char character = stream.get();
            string label(1, character);

            if (label == "\n") {
                label = "CR";
            }
            if (label == "\377") {
                break;
            }

            FrequencyElement* element = new FrequencyElement(label);
            table->InsertElement(element);
        }
    }

    table->Sort();

    FrequencyTable* copy = new FrequencyTable(table);

    HuffmanTree* tree = new HuffmanTree(copy);

    tree->SetCodes(table);

    ofstream output;

    cout << "Please input file name: " << endl;
    string outputFile;
    getline(cin, outputFile);

    output.open(outputFile);

    if (!output.is_open()) {
        cout << "Could not open output file: " << outputFile << endl;
    }
    else {
        output << table->PrintTableWithCodes();

        output.close();
    }
}

