/*
 * Filename: FrequencyElement.cpp
 * Description: Implementation of FrequencyElement
 * Author: Jason Woolley
 * Date: 6/8/2020
 * Course: Data Structures II
 */

#include "FrequencyElement.h"

//Constructor with a label and default other elements
FrequencyElement::FrequencyElement(const string& label) : _label(label), _count(1), _code("") {}

//Bunch of accessor functions
string FrequencyElement::GetLabel() const{
    return _label;
}

size_t FrequencyElement::GetCount() const{
    return _count;
}

string FrequencyElement::GetCode() const{
    return _code;
}

//Used to increase the count.  Restricts to just incrimenting it
void FrequencyElement::IncreaseCount() {
    _count++;
}

//Sets the code
void FrequencyElement::SetCode(const string& code) {
    _code = code;
}


//Operator overloads are used for comparing these easily
bool FrequencyElement::operator>(const FrequencyElement& rhs) const{
    return this->GetCount() > rhs.GetCount();
}

bool FrequencyElement::operator<(const FrequencyElement& rhs) const {
    return !(*this > rhs);
}

bool FrequencyElement::operator==(const FrequencyElement& rhs) const {
    return (this->GetLabel() == rhs.GetLabel());
}

bool FrequencyElement::operator!=(const FrequencyElement& rhs) const {
    return !(*this == rhs);
}

//Contructor with both label and count but no code yet
FrequencyElement::FrequencyElement(const string& label, const size_t& count) : _label(label), _count(count), _code(""){}




