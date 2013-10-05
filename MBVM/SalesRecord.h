//
//  SalesRecord.h
//  MBVM
//
//  Created by ogsh on 2013/10/06.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef __MBVM__SalesRecord__
#define __MBVM__SalesRecord__

#include <iostream>
#include <list>
#include "Receipt.h"

using namespace std;

/**
 *  商品売り上げを管理するクラス
 */
class SalesRecord {
public:
    
    /**
     *  売り上げを記録する
     *
     *  @param item 商品
     */
    void PushBack(const Item& item);
    
    /**
     *  売り上げ記録を出力する
     *
     *  @param os 出力先への参照
     *
     *  @return 出力先への参照
     */
    ostream& Dump(ostream& os);
    
private:
    list<Receipt> receipts;     ///< 売上記録
};

#endif /* defined(__MBVM__SalesRecord__) */
