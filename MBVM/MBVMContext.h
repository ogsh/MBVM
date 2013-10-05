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

using namespace std;

class MBVMState;

namespace MBVMStatus {
    enum typeID {
        AVAILABLE,
        OUT_OF_SERVICE,
        MAKING_COFFEE
    };
};

class MBVMContext {
public:
    MBVMContext(MBVMStatus::typeID status = MBVMStatus::AVAILABLE);
    
    void Run();
    MBVMStatus::typeID GetStatus() const;
    void SetStatus(MBVMStatus::typeID new_status);
    
private:
    MBVMStatus::typeID status;
    MBVMState* state;
};

#endif /* defined(__MBVM__MBVMContext__) */
