//
//  Item.h
//  MBVM
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef __MBVM__Item__
#define __MBVM__Item__

#include <iostream>
#include "recipe.h"
#include "Pay.h"

using namespace std;

class Item {
public:
    Item(CoffeeType::typeID coffee_type = CoffeeType::MARUKO, const string& name = "", int price = 0, const Pay& pay = Pay());
    
    friend ostream& operator<<(ostream& os, const Item& obj) {
        string dbar(30, '=');
        string bar(30, '-');

        os << dbar << endl;
        os << "名称: " << obj.name << "\t価格: " << obj.price << endl;
        os << bar << endl;
        os << "Recipe Information" << endl;
        os << bar << endl;
        os << obj.recipe;
        os << dbar << endl;
        return os;
    }
    
    int Supply();
    bool IsAvailable() const;
    string GetName() const;
    int GetPrice() const;
    
private:
    CoffeeType::typeID coffee_type;
    string name;
    int price;
    Recipe recipe;
    const Pay& pay;
};

#endif /* defined(__MBVM__Item__) */
