//
//  Sale.h
//  MBVM
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef __MBVM__Sale__
#define __MBVM__Sale__

#include <iostream>
#include <fstream>
#include <sstream>
#include "Pay.h"
#include "Item.h"
#include "SalesRecord.h"

using namespace std;

/**
 *  販売業務を行う
 */
class Sale {
public:
    Sale();

    /**
     *  販売可能な商品を表示
     */
    void ShowItems();
    
    /**
     *  商品を選択する
     *
     *  @param coffee_type 選択された商品
     *
     *  @return 商品の購入可否
     */
    bool SelectItem(CoffeeType::typeID coffee_type);

    /**
     *  商品を提供する
     *
     *  @param coffee_type 提供される商品の種類
     */
    void SupplyItem(CoffeeType::typeID coffee_type);
    
    /**
     *  硬貨を投入する
     *
     *  @param money_type 投入される硬貨の種類
     */
    void DropInCoin(MoneyType::typeID money_type);
    
    /**
     *  投入金額を払い戻す
     */
    void Refund();
    
    /**
     *  売り上げ記録を出力する
     *
     */
    void DumpSales(const string& filepath);
    
    /**
     *  Sale が持つ商品群を取得
     *
     *  @return 商品群
     */
    const map<CoffeeType::typeID, Item>& GetItems() const;
    
    /**
     *  Sale が持つ支払いオブジェクトを取得
     *
     *  @return 支払いオブジェクト
     */
    const Pay& GetPay() const;
    
    
private:
    Pay pay;
    map<CoffeeType::typeID, Item> items;
    SalesRecord record;
};

#endif /* defined(__MBVM__Sale__) */
