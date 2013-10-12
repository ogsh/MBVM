//
//  MBVMContext.cpp
//  MBVM
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#include "MBVMContext.h"

using namespace mbvm;

MBVMContext::MBVMContext(MBVMStatus status, MBVMState* state) : status(status), state(state), maintenance(Maintenance(this->sale)) {
}

void MBVMContext::Run(int event_id, int value) {
    this->state = (this->status == MBVMStatus::AVAILABLE)? MBVMStateAvailable::GetInstance() :
                  (this->status == MBVMStatus::OUT_OF_SERVICE)? MBVMStateOutOfService::GetInstance() :
                  MBVMStateMakingCoffee::GetInstance();
    this->state->Run(*this, event_id, value);
    this->maintenance.Maintain();
    this->sale.DumpSales("records.csv");
}

void MBVMContext::SetStatus(MBVMStatus new_status) {
    this->status = new_status;
}

MBVMStatus MBVMContext::GetStatus() const {
    return this->status;
}

void MBVMContext::Pay(MoneyType money_type) {
    this->sale.DropInCoin(money_type);
}

bool MBVMContext::SelectItem(CoffeeType coffee_type) {
    return this->sale.SelectItem(coffee_type);
}

void MBVMContext::SupplyItem(CoffeeType coffee_type) {
    this->sale.SupplyItem(coffee_type);
}

int MBVMContext::SupplyItem() {
    return this->sale.SupplyItem();
}

void MBVMContext::Cancel() {
    this->sale.Refund();
}