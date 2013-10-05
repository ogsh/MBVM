//
//  Sale.cpp
//  MBVM
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#include "Sale.h"

Sale::Sale() {
    this->items.insert(make_pair(CoffeeType::MARUKO, Item(CoffeeType::MARUKO, "マルコブレンド", 120, this->pay)));
    this->items.insert(make_pair(CoffeeType::SPECIAL, Item(CoffeeType::SPECIAL, "スペシャル", 150, this->pay)));
    this->items.insert(make_pair(CoffeeType::CAPPUCCINO, Item(CoffeeType::CAPPUCCINO, "カプチーノ", 180, this->pay)));
}


void Sale::ShowItems() {
    map<CoffeeType::typeID, Item>::iterator itr = this->items.begin();
    for(; itr != this->items.end(); ++itr) {
        cout << itr->second;
    }
}

bool Sale::SelectItem(CoffeeType::typeID coffee_type) {
    bool res = false;

    if(this->items[coffee_type].IsAvailable()) {
        this->pay.MakePayment(this->items[coffee_type].GetPrice());
        cout << this->items[coffee_type].GetName() << "を買いました\t" << "残金：" << this->pay.GetDeposit() << endl;
        res = true;
    }
    else {
        cout << this->items[coffee_type].GetName() << "は買えないよ\t" << "残金：" << this->pay.GetDeposit() << endl;
    }
    
    return res;
}

void Sale::SupplyItem(CoffeeType::typeID coffee_type) {
    this->items[coffee_type].Supply();
}

void Sale::DropInCoin(MoneyType::typeID money_type) {
    this->pay.AddDeposit(money_type);
    cout << "投入金額:" << this->pay.GetDeposit() << endl;
}

void Sale::Refund() {
    cout << "お金を払い戻します" << endl;
    this->pay.Refund();
    cout << "残金：" << pay.GetDeposit() << endl;
}