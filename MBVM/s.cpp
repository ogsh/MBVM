//
//  main.cpp
//  MBVM
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#include <iostream>
#include <list>
#include <utility>

#include "MBVMContext.h"

using namespace std;

void Test_csv(const string& fname);
void Test_case1();
void Test_context(MBVMContext& context);

int main(int argc, const char * argv[])
{
    DaoRecipe::Initialize("recipe.csv");
    MBVMContext context(MBVMStatus::AVAILABLE, MBVMStateAvailable::GetInstance());

    srand((unsigned int)time(NULL));
    
    Test_context(context);

    return 0;
}

void Test_context(MBVMContext& context) {
    string bar(35, '-');
    const int max_num_itr = 1000;
    int num_itr = 0;
    EventID::typeID events[] = {EventID::PAY, EventID::CANCEL, EventID::BUY, EventID::POWER};
    MoneyType::typeID moneys[] = {MoneyType::MONEY10, MoneyType::MONEY100, MoneyType::MONEY50, MoneyType::MONEY500};
    CoffeeType::typeID coffees[] = {CoffeeType::MARUKO, CoffeeType::SPECIAL, CoffeeType::CAPPUCCINO};
    
    int events_size = sizeof(events) / sizeof(EventID::typeID);
    int moneys_size = sizeof(moneys) / sizeof(MoneyType::typeID);
    int coffees_size = sizeof(coffees) / sizeof(CoffeeType::typeID);
    
    while(num_itr++ < max_num_itr) {
        const int max_num_event = 2;
        list<pair<int, int>> event_list;
        
        for(int i = 0; i < max_num_event; ++i) {
            int event_id = static_cast<int>(events[rand() % events_size]);
            int value = 0;
            if(event_id == EventID::PAY) {
                value = moneys[rand() % moneys_size];
            }
            else if(event_id == EventID::BUY) {
                value = coffees[rand() % coffees_size];
            }
            event_list.push_back(make_pair(event_id, value));
        }

        list<pair<int, int>>::iterator itr = event_list.begin();
        for(; itr != event_list.end(); ++itr) {
            cout << endl << "--- Event ID:" << itr->first << "\t|\t" << "value: " << itr->second << endl;
            cout << bar << endl;
            context.Run(itr->first, itr->second);
            cout << bar << endl;
        }
        
    }
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
