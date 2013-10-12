//
//  Maintenance.cpp
//  MBVM
//
//  Created by ogsh on 2013/10/06.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#include "Maintenance.h"

using namespace mbvm;

Maintenance::Maintenance(const Sale& sale) : sale(sale) {
}

bool Maintenance::Maintain() {
    bool is_water_temperature_normal = this->CheckWaterTemperature();   // 水温が適正範囲かどうか
    bool has_sufficient_ingredients = this->CheckIngredients();         // 商品を一つでも作れるだけの材料が残っているかどうか
    bool is_coin_pool_not_full = this->CheckCoinPool();                 // コインプールが満タンでないかどうか

    return is_water_temperature_normal && has_sufficient_ingredients && is_coin_pool_not_full;
}

void Maintenance::GoToAvailable() {
}

void Maintenance::GoToOutOfService() {
    // 販売可能ランプを消灯
    // コインシャッターを閉じる
    // 預かり金を返金
    // 商品選択ボタンを消す
    // 準備中メッセージを表示
    // 販売記録を出力
}

void Maintenance::GoToStandby() {
}

bool Maintenance::CheckCoinPool() {
    // コインプールが満タンかどうかチェックする処理を記述

    return true;
}

bool Maintenance::CheckIngredients() {
    bool res = false;
    map<CoffeeType, Item>::const_iterator itr = this->sale.GetItems().begin();
    
    for(; itr != this->sale.GetItems().end(); ++itr) {
        if(itr->second.HasSufficientIngredients()) {
            res = true;
            break;
        }
    }
    
    return res;
}

bool Maintenance::CheckWaterTemperature() {
    // 水温チェックの処理を記述
    
    return true;
}