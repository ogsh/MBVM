//
//  MBVMState.h
//  MBVM
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef __MBVM__MBVMState__
#define __MBVM__MBVMState__

#include <iostream>
#include "MBVMContext.h"


namespace mbvm {
    class MBVMContext;
    /**
     *  ステートパターン用インタフェース
     */
    class MBVMState {
    public:
        /**
         *  MBVMの状態に応じた処理を行う
         *
         *  @param context  MBVMコンテキスト
         *  @param event_id イベントID
         *  @param value    イベント値
         */
        virtual void Run(MBVMContext& context, int event_id, int value) = 0;
    };

    /**
     *  販売可能状態の時の処理
     */
    class MBVMStateAvailable : MBVMState {
    public:
        /**
         *  自身のインスタンスを取得する
         *
         *  @return 自身のインスタンスへのポインタ
         */
        static MBVMState* GetInstance();
        
        /**
         *  販売可能状態の時の処理
         *
         *  @param context  MBVMコンテキスト
         *  @param event_id イベントID
         *  @param value    イベント値
         */
        void Run(MBVMContext& context, int event_id, int value);
    private:
        static MBVMState* self;     ///< 自身へのポインタ

        /**
         *  シングルトンパターン用プライベートコンストラクタ
         */
        MBVMStateAvailable() {}
        
        /**
         *  シングルトンパターン用プライベートコピーコンストラクタ
         */
        MBVMStateAvailable(const MBVMStateAvailable& obj);
        
        /**
         *  シングルトンパターン用代入演算子オーバーロード
         *
         *  @param obj 自己参照
         *
         *  @return 自己参照
         */
        MBVMStateAvailable& operator=(const MBVMStateAvailable& obj);
    };

    /**
     *  MBVMが故障/調整中状態の時の処理
     */
    class MBVMStateOutOfService : MBVMState {
    public:
        /**
         *  自身のインスタンスへのポインタを取得
         *
         *  @return 自身へのインスタンスへのポインタ
         */
        static MBVMState* GetInstance();
        
        /**
         *  故障/調整中の時の処理を行う
         *
         *  @param context  MBVMコンテキスト
         *  @param event_id イベントID
         *  @param value    イベント値
         */
        void Run(MBVMContext& context, int event_id, int value);
    private:
        static MBVMState* self;

        /**
         *  シングルトンパターン用プライベートコンストラクタ
         */
        MBVMStateOutOfService() {}

        /**
         *  シングルトンパターン用プライベートコピーコンストラクタ
         */
        MBVMStateOutOfService(const MBVMStateAvailable& obj);

        /**
         *  シングルトンパターン用代入演算子オーバーロード
         *
         *  @param obj 自己参照
         *
         *  @return 自己参照
         */
        MBVMStateOutOfService& operator=(const MBVMStateAvailable& obj);
    };

    /**
     *  MBVMがコーヒー作成中の時の処理
     */
    class MBVMStateMakingCoffee : MBVMState {
    public:
        /**
         *  自身のインスタンスへのポインタを取得
         *
         *  @return 自身のインスタンスへのポインタ
         */
        static MBVMState* GetInstance();

        /**
         *  MBVMがコーヒー作成中の時の処理を行う
         *
         *  @param context  MBVMコンテキスト
         *  @param event_id イベントID
         *  @param value    イベント値
         */
        void Run(MBVMContext& context, int event_id, int value);
    private:
        static MBVMState* self;
       
        /**
         *  シングルトンパターン用プライベートコンストラクタ
         */
        MBVMStateMakingCoffee() {}

        /**
         *  シングルトンパターン用プライベートコピーコンストラクタ
         */
        MBVMStateMakingCoffee(const MBVMStateAvailable& obj);

        /**
         *  MBVMが故障/調整中の時の処理を行う
         *
         *  @param context  MBVMコンテキスト
         *  @param event_id イベントID
         *  @param value    イベント値
         */
        MBVMStateMakingCoffee& operator=(const MBVMStateAvailable& obj);
    };
}

#endif /* defined(__MBVM__MBVMState__) */
