//
// Created by rocki on 5/30/2020.
//

#include "FrequencyElement.h"
#include "FrequencyTable.h"

#include <string>
#include <list>
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;


int main() {
    ifstream stream;
    FrequencyTable table;

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

            FrequencyElement* element = new FrequencyElement(label);
            table.InsertElement(element);
        }
    }

    table.Sort();

    cout << "a" << endl;




}

