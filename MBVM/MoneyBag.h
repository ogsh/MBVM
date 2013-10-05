//
//  money_bag.h
//  InterprocessCommunication
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef __InterprocessCommunication__money_bag__
#define __InterprocessCommunication__money_bag__

#include <iostream>


namespace MoneyType {
    /**
     *  お金の種類
     */
    enum typeID {
        MONEY500 = 500, ///< 500円
        MONEY100 = 100, ///< 100円
        MONEY50  = 50,  ///< 50円
        MONEY10  = 10   ///< 10円
    };
};

/**
 *  預かり金をためるためのクラス
 */
class MoneyBag {
public:
    /**
     *  コンストラクタ
     */
    MoneyBag(int value = 0, int max_count = 50);

    /**
     *  コピーコンストラクタ
     */
    MoneyBag(const MoneyBag& obj);
    
    /**
     *  預かり金の数をインクリメント
     *
     *  @return 自己参照
     */
    MoneyBag& operator++();
    
    /**
     *  預かり金の数をインクリメント
     *
     *  @param n ダミー
     *
     *  @return 自身
     */
    MoneyBag operator++(int n);

    /**
     *  預かり金の数をデクリメント
     *
     *  @return 自己参照
     */
    MoneyBag& operator--();
    
    /**
     *  預かり金の数をデクリメント
     *
     *  @param n ダミー
     *
     *  @return 自身
     */
    MoneyBag operator--(int n);

    /**
     *  代入演算子オーバーロード
     *
     *  @param obj 代入するMoneyBagオブジェクト
     *
     *  @return 自己参照
     */
    MoneyBag& operator=(const MoneyBag& obj);
    
    /**
     *  比較演算子オーバーロード
     *
     *  @param obj 比較されるMoneyBagオブジェクト
     *
     *  @return 比較結果
     */
    bool operator<=(const MoneyBag& obj) const;

    /**
     *  比較演算子オーバーロード
     *
     *  @param obj 比較されるMoneyBagオブジェクト
     *
     *  @return 比較結果
     */
    bool operator<(const MoneyBag& obj) const;

    /**
     *  比較演算子オーバーロード
     *
     *  @param obj 比較されるMoneyBagオブジェクト
     *
     *  @return 比較結果
     */
    bool operator>=(const MoneyBag& obj) const;

    /**
     *  比較演算子オーバーロード
     *
     *  @param obj 比較されるMoneyBagオブジェクト
     *
     *  @return 比較結果
     */
    bool operator>(const MoneyBag& obj) const;

    /**
     *  出力用シフト演算子オーバーロード
     *
     *  @param os  出力先への参照
     *  @param obj 出力されるMoneyBagオブジェクト
     *
     *  @return 出力先への参照
     */
    friend std::ostream& operator<<(std::ostream& os, const MoneyBag& obj);

    /**
     *  自身が持っている合計金額を取得する
     *
     *  @return 合計金額
     */
    int AmountOfMoney() const;
    
    /**
     *  自身が持つお金の価格を取得する
     *
     *  @return 金額
     */
    int GetValue() const;

    /**
     *  自身が持つお金の数を取得する
     *
     *  @return お金の数
     */
    int GetCount() const;
    
    /**
     *  お金の数をセットする
     *
     *  @param count お金の数
     */
    void SetCount(int count);
    
private:
    int value;      ///< 自身が持つお金の価格
    int count;      ///< 自身が持つお金の数
    int max_count;  ///< 最大保持することのできるお金の数
};

#endif /* defined(__InterprocessCommunication__money_bag__) */
