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
    
}


MBVMState* MBVMStateOutOfService::self = NULL;

MBVMState* MBVMStateOutOfService::GetInstance() {
    if(self == NULL) {
        self = new MBVMStateOutOfService();
    }
    return self;
}

void MBVMStateOutOfService::Run(MBVMContext& context, int event_id, int value) {
    
}


MBVMState* MBVMStateMakingCoffee::self = NULL;

MBVMState* MBVMStateMakingCoffee::GetInstance() {
    if(self == NULL) {
        self = new MBVMStateMakingCoffee();
    }
    return self;
}

void MBVMStateMakingCoffee::Run(MBVMContext& context, int event_id, int value) {
    
}
