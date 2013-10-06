//
//  Receipt.cpp
//  MBVM
//
//  Created by ogsh on 2013/10/06.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#include "Receipt.h"

Receipt::Receipt() : date(Util::Time::GetNow()) {
    
}

Receipt::Receipt(const Item& item) : date(Util::Time::GetNow()), item(item) {
}

ostream& operator<<(ostream& os, const Receipt& obj) {
    os << obj.date.year << "/"
    << obj.date.month
    << "/"
    << obj.date.day
    << " "
    << obj.date.hour
    << ":"
    << obj.date.min
    << ":"
    << obj.date.sec;
   
    os  << ",";
    
    os << obj.item.GetName() << ","
    << obj.item.GetPrice();
    
    return os;
}