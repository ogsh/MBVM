//
//  Maintenance.h
//  MBVM
//
//  Created by ogsh on 2013/10/06.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef __MBVM__Maintenance__
#define __MBVM__Maintenance__

#include <iostream>
#include <map>

#include "Sale.h"

/**
 *  MBVMのメンテナンスを行うクラス
 */
class Maintenance {
public:
    /**
     *  コンストラクタ
     */
    Maintenance(const Sale& sale);
    
    /**
     *  メンテナンスを行う
     *
     *  @return メンテナンス結果
     */
    bool Maintain();
    
    /**
     *  故障/調整中状態に遷移させる
     */
    void GoToOutOfService();
    
    /**
     *  販売可能状態に遷移させる
     */
    void GoToAvailable();
    
    /**
     *  待機状態に遷移させる
     */
    void GoToStandby();
    
    const Sale& GetSale() const {
        return this->sale;
    }

private:
    const Sale& sale;

    /**
     *  コインプールの状態をチェックする
     *
     *  @return コインプールが満タンかどうか
     */
    bool CheckCoinPool();
    
    /**
     *  水温をチェックする
     *
     *  @return 水温が適正範囲かどうか
     */
    bool CheckWaterTemperature();
    
    /**
     *  材料の残量をチェックする
     *
     *  @return 十分な残量があるかどうか
     */
    bool CheckIngredients();
};

#endif /* defined(__MBVM__Maintenance__) */
