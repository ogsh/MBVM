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
    map<CoffeeType, Item>::iterator itr = this->items.begin();
    for(; itr != this->items.end(); ++itr) {
        cout << itr->second;
    }
}

bool Sale::SelectItem(CoffeeType coffee_type) {
    bool res = false;

    if(this->items[coffee_type].IsAvailable()) {
        this->items[coffee_type].isSelected = true;
        this->pay.MakePayment(this->items[coffee_type].GetPrice());
        this->record.PushBack(this->items[coffee_type]);
        cout << this->items[coffee_type].GetName() << "を買いました\t" << "残金：" << this->pay.GetDeposit() << endl;
        res = true;
    }
    else {
        cout << this->items[coffee_type].GetName() << "は買えないよ\t" << "残金：" << this->pay.GetDeposit() << endl;
    }
    
    return res;
}

int Sale::SupplyItem() {
    int progress = -1;
    map<CoffeeType, Item>::iterator itr = this->items.begin();
    for(; itr != this->items.end(); ++itr) {
        if(itr->second.isSelected) {
            progress = itr->second.Supply();
            break;
        }
    }
    return progress;
}

void Sale::SupplyItem(CoffeeType coffee_type) {
    this->items[coffee_type].Supply();
}

void Sale::DropInCoin(MoneyType money_type) {
    this->pay.AddDeposit(money_type);
    cout << "投入金額:" << this->pay.GetDeposit() << endl;
}

void Sale::Refund() {
    cout << "お金を払い戻します" << endl;
    this->pay.Refund();
    cout << "残金：" << pay.GetDeposit() << endl;
}

void Sale::DumpSales(const string& filepath) {
    ofstream os(filepath, ios::app | ios::out);
    this->record.Dump(os);
    os.close();
    
}


const map<CoffeeType, Item>& Sale::GetItems() const {
    return this->items;
}

const Pay& Sale::GetPay() const {
    return this->pay;
}