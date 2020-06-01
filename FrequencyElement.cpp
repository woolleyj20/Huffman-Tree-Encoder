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
    if (*this == rhs){
        return false;
    }

    if (this->GetCount() > rhs.GetCount()) {
        return true;
    }
    else if (this->GetCount() < rhs.GetCount()) {
        return false;
    }

    else {
        return this->GetLabel() > rhs.GetLabel();
    }
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


