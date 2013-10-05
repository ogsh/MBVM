//
//  MBVMContext.h
//  MBVM
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef __MBVM__MBVMContext__
#define __MBVM__MBVMContext__

#include <iostream>
#include "MBVMState.h"
#include "Sale.h"

using namespace std;

class MBVMState;

namespace MBVMStatus {
    enum typeID {
        AVAILABLE,
        OUT_OF_SERVICE,
        MAKING_COFFEE
    };
};

namespace EventID {
    enum typeID {
        PAY = 302,
        BUY = 303,
        CANCEL = 304,
        POWER = 400
    };
};

class MBVMContext {
public:
    MBVMContext(MBVMStatus::typeID status, MBVMState* state);
    
    void Run(int event_id, int value);
    MBVMStatus::typeID GetStatus() const;
    void SetStatus(MBVMStatus::typeID new_status);
    
    void Pay(MoneyType::typeID money_type);
    bool SelectItem(CoffeeType::typeID coffee_type);
    void SupplyItem(CoffeeType::typeID coffee_type);
    void Cancel();
    
private:
    MBVMStatus::typeID status;
    MBVMState* state;
    Sale sale;
};

#endif /* defined(__MBVM__MBVMContext__) */
