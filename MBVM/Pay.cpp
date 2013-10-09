//
//  pay.cpp
//  InterprocessCommunication
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#include "Pay.h"


Pay::Pay(int max_deposit) : max_deposit(max_deposit) {
    this->money_bags.insert(std::make_pair(MoneyType::MONEY500, MoneyBag(500, 50)));
    this->money_bags.insert(std::make_pair(MoneyType::MONEY100, MoneyBag(100, 50)));
    this->money_bags.insert(std::make_pair(MoneyType::MONEY50,  MoneyBag(50,  50)));
    this->money_bags.insert(std::make_pair(MoneyType::MONEY10,  MoneyBag(10,  50)));
}

Pay& Pay::AddDeposit(MoneyType::typeID money_type) {
    int deposit = this->GetDeposit();
    ++ this->money_bags[money_type];
    cout << this->money_bags[money_type];

    if(deposit + static_cast<int>(money_type) > this->max_deposit) {
        cout << "投入金額が" << max_deposit << "円を超えたので" << money_type << "円を払い戻します" << endl;
        -- this->money_bags[money_type];
    }

    return *this;
}

bool Pay::MakePayment(int price) {
    int deposit = this->GetDeposit();
    
    if(deposit < price) {
        return false;
    }
    
    deposit -= price;
    
    map<MoneyType::typeID, MoneyBag>::iterator itr = this->money_bags.begin();
    for(itr = this->money_bags.begin(); itr != this->money_bags.end(); ++itr) {
        int required_coins = deposit / itr->second.GetValue();
        itr->second.SetCount(required_coins);
        deposit -= itr->second.AmountOfMoney();
    }
    
    return true;
}


void Pay::Refund() {
    map<MoneyType::typeID, MoneyBag>::iterator itr = this->money_bags.begin();
    for(; itr != this->money_bags.end(); ++itr) {
        while(itr->second.GetCount() > 0) {
            --itr->second;
        }
    }
}

int Pay::GetDeposit() const {
    int deposit = 0;
    map<MoneyType::typeID, MoneyBag>::const_iterator itr = this->money_bags.begin();

    for(; itr != this->money_bags.end(); ++itr) {
        deposit += itr->second.AmountOfMoney();
    }
    
    return deposit;
}