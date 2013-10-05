//
//  MBVMContext.cpp
//  MBVM
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#include "MBVMContext.h"


MBVMContext::MBVMContext(MBVMStatus::typeID status) : status(status) , state(MBVMStateAvailable::GetInstance()) {
}

void MBVMContext::Run() {
    this->state = (this->status == MBVMStatus::AVAILABLE)? MBVMStateAvailable::GetInstance() :
                  (this->status == MBVMStatus::OUT_OF_SERVICE)? MBVMStateOutOfService::GetInstance() :
                  MBVMStateMakingCoffee::GetInstance();
    this->state->Run(*this, 0, 0);
}

void MBVMContext::SetStatus(MBVMStatus::typeID new_status) {
    this->status = new_status;
}

MBVMStatus::typeID MBVMContext::GetStatus() const {
    return this->status;
}