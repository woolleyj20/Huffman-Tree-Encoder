/*
 * Filename: main.cpp
 * Description: Main file that handles the files and calling appropriate functions to encode and decode
 * Author: Jason Woolley
 * Date: 6/8/2020
 * Course: Data Structures II
 */

#include "FrequencyElement.h"
#include "FrequencyTable.h"
#include "HuffmanTree.h"

#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;



int main(int argc, char* argv[]) {
    if (strcmp(argv[1], "-encode") == 0) {
        ifstream input;
        FrequencyTable* table = new FrequencyTable();


        input.open(argv[2]);

        if (!input.is_open()) {
            cout << "Could not open file: " << argv[2] << endl;
        }
        // In this loop, it pulls every character, makes an element from it, and inserts it into the table.
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

        //Sort the table
        table->Sort();

        //Make a copy for making the tree
        FrequencyTable* copy = new FrequencyTable(table);

        //Make a tree!
        HuffmanTree* tree = new HuffmanTree(copy);

        //Set codes in the original from the tree
        tree->SetCodes(table);

        //Output codes
        cout << table->PrintTableWithCodes() << endl;

        ofstream output;

        output.open(argv[3]);
        input.open(argv[2]);



        // Write the encoded file
        if (!output.is_open()) {
            cout << "Could not open output file: " << argv[3] << endl;
        } else {
            if (!input.is_open()) {
                cout << "Could not open in file: " << argv[2] << endl;
            } else {
                table->WriteEncodedFile(input, output);
            }
        }

        input.close();
        output.close();

        delete table;
        delete copy;
        delete tree;
    }
    else {
        //This is just here in case something goes wrong
        cout << "Dummy" << endl;
    }
}



