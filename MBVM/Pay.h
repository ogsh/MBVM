//
//  pay.h
//  InterprocessCommunication
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef __InterprocessCommunication__pay__
#define __InterprocessCommunication__pay__

#include <iostream>
#include <map>

#include "MoneyBag.h"

using namespace std;

class Pay {
public:
    Pay();
    Pay& AddDeposit(MoneyType::typeID money_type);
    bool MakePayment(int price);
    
    void Refund();
    
private:
    
    static int moneys[4];
    map<MoneyType::typeID, MoneyBag> money_bags;
};

#endif /* defined(__InterprocessCommunication__pay__) */
