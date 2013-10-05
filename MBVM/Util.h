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

/**
 *  ユーティリティクラス
 */
class Util {
public:
    /**
     *  文字列を数値に変換する
     *
     *  @param str 変換したい文字列
     *
     *  @return 変換して得られた値
     */
    template<class T>
    static T StrToNum(const std::string& str) {
        T res;
        std::stringstream ss;
        ss << str;
        ss >> res;
        return res;
    }
    
    /**
     *  数値を文字列に変換する
     *
     *  @param num 変換したい数値
     *
     *  @return 変換して得られた文字列
     */
    template <class T>
    static std::string NumToStr(T num) {
        std::stringstream ss;
        ss << num;
        return ss.str();
    }
};

#endif
