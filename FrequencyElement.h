//
// Created by rocki on 5/31/2020.
//

#ifndef HUFFMAN_WOOLLEYJ20_FREQUENCYELEMENT_H
#define HUFFMAN_WOOLLEYJ20_FREQUENCYELEMENT_H

#include <string>

using namespace std;

class FrequencyElement {
    string _label;
    size_t _count;
    string _code;
public:
    FrequencyElement(const string& label);
    FrequencyElement(const string& label, const size_t& count);

    string GetLabel() const;
    size_t GetCount() const;
    string GetCode() const;
    void IncreaseCount();
    void SetCode(const string& code);

    bool operator>(const FrequencyElement& rhs)const ;
    bool operator<(const FrequencyElement& rhs)const ;
    bool operator==(const FrequencyElement& rhs)const ;
    bool operator!=(const FrequencyElement& rhs)const ;
};


#endif //HUFFMAN_WOOLLEYJ20_FREQUENCYELEMENT_H
