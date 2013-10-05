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
#include "MBVMContext.h"

class MBVMContext;

class MBVMState {
public:
    virtual void Run(MBVMContext& context, int event_id, int value) = 0;
};

class MBVMStateAvailable : MBVMState {
public:
    static MBVMState* GetInstance();
    void Run(MBVMContext& context, int event_id, int value);
private:
    static MBVMState* self;
    
    MBVMStateAvailable() {}
    MBVMStateAvailable(const MBVMStateAvailable& obj);
    MBVMStateAvailable& operator=(const MBVMStateAvailable& obj);
};

class MBVMStateOutOfService : MBVMState {
public:
    static MBVMState* GetInstance();
    void Run(MBVMContext& context, int event_id, int value);
private:
    static MBVMState* self;
    
    MBVMStateOutOfService() {}
    MBVMStateOutOfService(const MBVMStateAvailable& obj);
    MBVMStateOutOfService& operator=(const MBVMStateAvailable& obj);
};

class MBVMStateMakingCoffee : MBVMState {
public:
    static MBVMState* GetInstance();
    void Run(MBVMContext& context, int event_id, int value);
private:
    static MBVMState* self;
    
    MBVMStateMakingCoffee() {}
    MBVMStateMakingCoffee(const MBVMStateAvailable& obj);
    MBVMStateMakingCoffee& operator=(const MBVMStateAvailable& obj);
};


#endif /* defined(__MBVM__MBVMState__) */
