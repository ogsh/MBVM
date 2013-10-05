//
//  pay.cpp
//  InterprocessCommunication
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#include "Pay.h"

int Pay::moneys[4] = {500, 100, 50, 10};

Pay::Pay() {
    this->money_bags.insert(std::make_pair(MoneyType::MONEY500, MoneyBag(500, 50)));
    this->money_bags.insert(std::make_pair(MoneyType::MONEY100, MoneyBag(100, 50)));
    this->money_bags.insert(std::make_pair(MoneyType::MONEY50,  MoneyBag(50,  50)));
    this->money_bags.insert(std::make_pair(MoneyType::MONEY10,  MoneyBag(10,  50)));
}

Pay& Pay::AddDeposit(MoneyType::typeID money_type) {
    ++ this->money_bags[money_type];
    std::cout << this->money_bags[money_type];
    return *this;
}

bool Pay::MakePayment(int price) {
    int deposit = 0;
    
    map<MoneyType::typeID, MoneyBag>::iterator itr = this->money_bags.begin();
    for(; itr != this->money_bags.end(); ++itr) {
        deposit += itr->second.GetValue();
    }
    if(deposit < price) {
        return false;
    }

    for(itr = this->money_bags.begin(); itr != this->money_bags.end(); ++itr) {
        itr->second.SetCount(0);
    }
    
    
    return true;
}


void Pay::Refund() {
    map<MoneyType::typeID, MoneyBag>::iterator itr = this->money_bags.begin();
    for(; itr != this->money_bags.end(); ++itr) {
        for(; itr->second.GetCount() > 0; --itr->second) {
            std::cout << itr->second;
        }
        std::cout << itr->second << std::endl;
    }
}