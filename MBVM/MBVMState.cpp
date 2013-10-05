//
//  MBVMState.cpp
//  MBVM
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#include "MBVMState.h"

MBVMState* MBVMStateAvailable::self = NULL;

MBVMState* MBVMStateAvailable::GetInstance() {
    if(self == NULL) {
        self = new MBVMStateAvailable();
    }
    return self;
}

void MBVMStateAvailable::Run(MBVMContext& context, int event_id, int value) {
    switch(event_id) {
        case EventID::POWER:
            context.SetStatus(MBVMStatus::OUT_OF_SERVICE);
            break;
        case EventID::BUY:
            if(context.SelectItem(static_cast<CoffeeType::typeID>(value))) {
                context.SetStatus(MBVMStatus::MAKING_COFFEE);
                context.SupplyItem(static_cast<CoffeeType::typeID>(value));
            }
            break;
        case EventID::PAY:
            context.Pay(static_cast<MoneyType::typeID>(value));
            break;
        case EventID::CANCEL:
            context.Cancel();
            break;
        default:
            break;
    }
}


MBVMState* MBVMStateOutOfService::self = NULL;

MBVMState* MBVMStateOutOfService::GetInstance() {
    if(self == NULL) {
        self = new MBVMStateOutOfService();
    }
    return self;
}

void MBVMStateOutOfService::Run(MBVMContext& context, int event_id, int value) {
    if(event_id == EventID::POWER) {
        context.SetStatus(MBVMStatus::AVAILABLE);
    }
}

MBVMState* MBVMStateMakingCoffee::self = NULL;

MBVMState* MBVMStateMakingCoffee::GetInstance() {
    if(self == NULL) {
        self = new MBVMStateMakingCoffee();
    }
    return self;
}

void MBVMStateMakingCoffee::Run(MBVMContext& context, int event_id, int value) {
    context.SetStatus(MBVMStatus::AVAILABLE);
}
