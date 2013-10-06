//
//  pay.h
//  InterprocessCommunication
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef __InterprocessCommunication__pay__
#define __InterprocessCommunication__pay__

#include <iostream>
#include <map>
#include <vector>

#include "MoneyBag.h"

using namespace std;

/**
 *  支払い業務を行う
 */
class Pay {
public:
    /**
     *  デフォルトコンストラクタ
     */
    Pay(int max_deposit = 999);
    
    /**
     *  硬貨を預かり金に投入する
     *
     *  @param money_type 投入される硬貨の種類
     *
     *  @return 自己参照
     */
    Pay& AddDeposit(MoneyType::typeID money_type);
    
    /**
     *  支払いを行う
     *
     *  @param price 購入される商品の価格
     *
     *  @return 購入可否
     */
    bool MakePayment(int price);
    
    /**
     *  預かり金を取得する
     *
     *  @return 預かり金
     */
    int GetDeposit() const;

    /**
     *  投入金額を払い戻す
     */
    void Refund();
    
private:
    int max_deposit;
    map<MoneyType::typeID, MoneyBag, greater<MoneyType::typeID>> money_bags;
};

#endif /* defined(__InterprocessCommunication__pay__) */
