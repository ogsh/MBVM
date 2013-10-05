//
//  money_bag.h
//  InterprocessCommunication
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef __InterprocessCommunication__money_bag__
#define __InterprocessCommunication__money_bag__

#include <iostream>

namespace MoneyType {
    enum typeID {
        MONEY500 = 500,
        MONEY100 = 100,
        MONEY50  = 50,
        MONEY10  = 10
    };
};

class MoneyBag {
public:
    MoneyBag(int value = 0, int max_count = 50);

    MoneyBag(const MoneyBag& obj);
    
    MoneyBag& operator++();
    MoneyBag operator++(int n);
    MoneyBag& operator--();
    MoneyBag operator--(int n);
    MoneyBag& operator=(const MoneyBag& obj);
    bool operator<=(const MoneyBag& obj) const;
    bool operator<(const MoneyBag& obj) const;
    bool operator>=(const MoneyBag& obj) const;
    bool operator>(const MoneyBag& obj) const;
    friend std::ostream& operator<<(std::ostream& os, const MoneyBag& obj);

    int GetValue() const;

    int GetCount() const;

    void SetCount(int count);
    
private:
    int value;
    int count;
    int max_count;
};

#endif /* defined(__InterprocessCommunication__money_bag__) */
