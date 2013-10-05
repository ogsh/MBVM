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

int Sale::SelectItem(CoffeeType::typeID coffee_type) {
    if(this->items[coffee_type].IsAvailable()) {
        this->pay.MakePayment(this->items[coffee_type].GetPrice());
        cout << this->items[coffee_type].GetName() << "を買いました" <<endl;
    }
    else {
        cout << this->items[coffee_type].GetName() << "は買えないよ" << endl;
        return -1;
    }
    
    this->items[coffee_type].Supply();

    return 0;
}

void Sale::DropInCoin(MoneyType::typeID money_type) {
    this->pay.AddDeposit(money_type);
}