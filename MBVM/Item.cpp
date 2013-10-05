//
//  Item.cpp
//  MBVM
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#include "Item.h"

Item::Item(CoffeeType::typeID coffee_type, const string& name, int price, const Pay& pay) :
coffee_type(coffee_type), name(name), price(price), recipe(Recipe(coffee_type)), pay(pay) {
    
}

int Item::Supply() {
    cout << this->name << "をつくります．";
    this->recipe.Make();
    return 0;
}

bool Item::IsAvailable() const {
    return this->price <= this->pay.GetDeposit();
}

int Item::GetPrice() const {
    return this->price;
}

string Item::GetName() const {
    return this->name;
}