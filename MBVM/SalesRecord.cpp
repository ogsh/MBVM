//
//  SalesRecord.cpp
//  MBVM
//
//  Created by ogsh on 2013/10/06.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#include "SalesRecord.h"

void SalesRecord::PushBack(const Item &item) {
    this->receipts.push_back(Receipt(item));
}

ostream& SalesRecord::Dump(ostream &os) {
    list<Receipt>::iterator itr = this->receipts.begin();
    for(; itr != this->receipts.end(); ++itr) {
        os << *itr << endl;
    }
    
    this->receipts.clear();

    return os;
}