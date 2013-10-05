//
//  main.cpp
//  MBVM
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#include <iostream>
#include "CSV.h"
#include "Sale.h"


using namespace std;

void Test_csv(const string& fname);
void Test_case1();

int main(int argc, const char * argv[])
{
    DaoRecipe::Initialize("recipe.csv");

    Test_case1();
    return 0;
}

void Test_case1() {
    Sale sale;
    
    sale.ShowItems();

    MoneyType::typeID moneys[] = {
        MoneyType::MONEY10,
        MoneyType::MONEY500,
        MoneyType::MONEY500,
        MoneyType::MONEY500,
        MoneyType::MONEY100,
    };
    
    for(int i=0; i < sizeof(moneys) / sizeof(MoneyType::typeID); ++i) {
        sale.DropInCoin(moneys[i]);
    }
    
    
    sale.SelectItem(CoffeeType::MARUKO);
    sale.SelectItem(CoffeeType::SPECIAL);
    sale.SelectItem(CoffeeType::CAPPUCCINO);
    
    sale.Refund();
}

void Test_csv(const string& fname) {
    
    CSV csv (fname);
    
    cout << csv;
}
