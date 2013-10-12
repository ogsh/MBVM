//
//  Item.cpp
//  MBVM
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#include "Item.h"

Item::Item(CoffeeType coffee_type, const string& name, int price, const Pay& pay) :
isSelected(false), coffee_type(coffee_type), name(name), price(price), recipe(Recipe(coffee_type)), pay(pay) {
    
}

int Item::Supply() {
    if(this->recipe.GetProgress() == 0) {
        cout << this->name << "をつくります" << endl;
    }
    else {
        cout << this->name << "を作ってます" << endl;
    }
    int progress = this->recipe.Make();
    
    if(progress == 0) {
        this->isSelected = false;
    }
    
    return progress;
}

bool Item::IsAvailable() const {
    return ( this->price <= this->pay.GetDeposit() && this->HasSufficientIngredients() );
}

bool Item::HasSufficientIngredients() const {
    return this->recipe.HasSufficientIngredients();
}

int Item::GetProgress() const {
    return this->recipe.GetProgress();
}

int Item::GetPrice() const {
    return this->price;
}

string Item::GetName() const {
    return this->name;
}