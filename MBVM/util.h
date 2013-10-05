//
//  Util.h
//  MBVM
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef MBVM_Util_h
#define MBVM_Util_h

#include <iostream>
#include <sstream>

class Util {
public:
    template<class T>
    static T StrToNum(const std::string& str) {
        T res;
        std::stringstream ss;
        ss << str;
        ss >> res;
        return res;
    }
    template <class T>
    static std::string NumToStr(T num) {
        std::stringstream ss;
        ss << num;
        return ss.str();
    }
};

#endif
