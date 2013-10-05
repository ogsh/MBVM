//
//  MBVMState.h
//  MBVM
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef __MBVM__MBVMState__
#define __MBVM__MBVMState__

#include <iostream>

namespace MBVMStatus {
    enum typeID {
        AVAILABLE,
        OUT_OF_SERVICE,
        MAKING_COFFEE
    };
};

class MBVMState {
public:
    virtual MBVMStatus::typeID Run(int event_id, int value) = 0;
};

class MBVMStateAvailable : MBVMState {
public:
    MBVMStatus::typeID Run(int event_id, int value) {
        MBVMStatus::typeID status = MBVMStatus::AVAILABLE;
        
        return status;
    }
};

class MBVMStateOutOfService : MBVMState {
public:
    MBVMStatus::typeID Run(int event_id, int value) {
        MBVMStatus::typeID status = MBVMStatus::AVAILABLE;
        
        return status;
    }
};

class MBVMStateMakingCoffee : MBVMState {
public:
    MBVMStatus::typeID Run(int event_id, int value) {
        MBVMStatus::typeID status = MBVMStatus::AVAILABLE;
        
        return status;
    }
};

#endif /* defined(__MBVM__MBVMState__) */
