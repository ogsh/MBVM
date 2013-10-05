//
//  money_bag.cpp
//  InterprocessCommunication
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#include "MoneyBag.h"

MoneyBag::MoneyBag(int value, int max_count) : value(value), count(0), max_count(max_count) {
}

MoneyBag::MoneyBag(const MoneyBag& obj) : count(obj.count), value(obj.value), max_count(obj.max_count) {
}

MoneyBag& MoneyBag::operator++() {
    if(this->count < this->max_count) {
        ++ this->count;
    }
    else {
        std::cerr << "money bag is full" << std::endl;
    }
    return *this;
}

MoneyBag MoneyBag::operator++(int n) {
    MoneyBag self = *this;
    if(this->count < this->max_count) {
        ++ this->count;
    }
    else {
        std::cerr << "money bag is full" << std::endl;
    }
    return self;
}

MoneyBag& MoneyBag::operator--() {
    if(this->count > 0) {
        -- this->count;
        std::cout << "refund[" << this->value << "]\t" << this->count << " /" << this->max_count << std::endl;
    }
    else {
        std::cerr << "money bag is empty" << std::endl;
    }
    return *this;
}

MoneyBag MoneyBag::operator--(int n) {
    MoneyBag self = *this;
    
    if(this->count > 0) {
        -- this->count;
    }
    else {
        std::cerr << "money bag is empty" << std::endl;
    }
    return self;
}


MoneyBag& MoneyBag::operator=(const MoneyBag& obj) {
    this->count = obj.count;
    this->value = obj.value;
    this->max_count = obj.max_count;
    return *this;
}

bool MoneyBag::operator<=(const MoneyBag& obj) const {
    return this->count <= obj.count;
}

bool MoneyBag::operator<(const MoneyBag& obj) const {
    return this->count < obj.count;
}

bool MoneyBag::operator>=(const MoneyBag& obj) const {
    return this->count >= obj.count;
}

bool MoneyBag::operator>(const MoneyBag& obj) const {
    return this->count > obj.count;
}

std::ostream& operator<<(std::ostream& os, const MoneyBag& obj) {
    os << "pay[" << obj.value << "]" << "\t" << obj.count << " /" << obj.max_count << std::endl;
    return os;
}

int MoneyBag::GetValue() const {
    return this->value;
}

int MoneyBag::AmountOfMoney() const {
    return this->count * this->value;
}

int MoneyBag::GetCount() const {
    return this->count;
}

void MoneyBag::SetCount(int count) {
    this->count = (count > 0)? count : 0;
}