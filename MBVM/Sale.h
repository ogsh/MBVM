//
//  Sale.h
//  MBVM
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef __MBVM__Sale__
#define __MBVM__Sale__

#include <iostream>
#include "Pay.h"
#include "Item.h"

using namespace std;

class Sale {
public:
    Sale();
    
    void ShowItems();
    int SelectItem(CoffeeType::typeID coffee_type);
    
    void DropInCoin(MoneyType::typeID money_type);
    
private:
    Pay pay;
    map<CoffeeType::typeID, Item, greater<CoffeeType::typeID>> items;
    
};

#endif /* defined(__MBVM__Sale__) */
