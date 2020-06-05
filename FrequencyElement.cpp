//
// Created by rocki on 5/31/2020.
//

#include "FrequencyElement.h"

FrequencyElement::FrequencyElement(const string& label) : _label(label), _count(1), _code("") {}

string FrequencyElement::GetLabel() const{
    return _label;
}

size_t FrequencyElement::GetCount() const{
    return _count;
}

string FrequencyElement::GetCode() const{
    return _code;
}

void FrequencyElement::IncreaseCount() {
    _count++;
}

void FrequencyElement::SetCode(const string& code) {
    _code = code;
}

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

FrequencyElement::FrequencyElement(const string& label, const size_t& count) : _label(label), _count(count), _code(""){}




