//
//  MBVMContext.h
//  MBVM
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef __MBVM__MBVMContext__
#define __MBVM__MBVMContext__

#include <iostream>
#include "MBVMState.h"
#include "Sale.h"
#include "Maintenance.h"

using namespace std;

namespace mbvm {
    class MBVMState;

    /**
     *  MBVMの状態
     */
    enum MBVMStatus {
        AVAILABLE,          ///< 販売可能
        OUT_OF_SERVICE,     ///< 故障中または調整中
        MAKING_COFFEE       ///< コーヒー作成中
    };

    /**
     *  イベントの種類
     */
    enum EventID {
        PAY = 302,          ///< 支払いイベント
        BUY = 303,          ///< 商品購入イベント
        CANCEL = 304,       ///< キャンセルイベント
        POWER = 400         ///< 電源イベント
    };

    /**
     *  MBVMコンテキスト
     */
    class MBVMContext {
    public:
        /**
         *  コンストラクタ
         */
        MBVMContext(MBVMStatus status, MBVMState* state);

        /**
         *  イベントに応じて処理を行う
         *
         *  @param event_id イベントの種類
         *  @param value    イベントが持つ値
         */
        void Run(int event_id, int value);

        /**
         *  MBVMの状態を取得する
         *
         *  @return MBVMの状態
         */
        MBVMStatus GetStatus() const;
        
        /**
         *  MBVMの状態をセットする
         *
         *  @param new_status セットするMBVMの状態
         */
        void SetStatus(MBVMStatus new_status);

        /**
         *  硬貨投入を行う
         *
         *  @param money_type 投入される硬貨の種類
         */
        void Pay(MoneyType money_type);
        
        /**
         *  商品を選択する
         *
         *  @param coffee_type 選択された商品の種類
         *
         *  @return 購入可能の可否
         */
        bool SelectItem(CoffeeType coffee_type);
        
        /**
         *  コーヒーを提供する
         *
         *  @param coffee_type 提供されるコーヒーの種類
         */
        void SupplyItem(CoffeeType coffee_type);
        
        /**
         *  選択済みのコーヒーを提供する
         *  @return コーヒー作成進捗度合い
         */
        int SupplyItem();
        
        
        /**
         *  商品購入を取り消す
         */
        void Cancel();
        
    private:
        MBVMStatus status;  ///< MBVMの状態
        MBVMState* state;           ///< MBVMの状態に応じて処理を行うためのオブジェクト
        Sale sale;                  ///< 販売
        Maintenance maintenance;    ///< メンテナンス
    };
}

#endif /* defined(__MBVM__MBVMContext__) */
