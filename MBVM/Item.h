//
//  Item.h
//  MBVM
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef __MBVM__Item__
#define __MBVM__Item__

#include <iostream>
#include "Recipe.h"
#include "Pay.h"

using namespace std;

/**
 *  商品
 */
class Item {
public:
    /**
     *  コンストラクタ
     */
    Item(CoffeeType::typeID coffee_type = CoffeeType::MARUKO, const string& name = "", int price = 0, const Pay& pay = Pay());

    /**
     *  出力用シフト演算子オーバーロード
     *
     *  @param os  出力先への参照
     *  @param obj 出力されるItemオブジェクト
     *
     *  @return 出力先への参照
     */
    friend ostream& operator<<(ostream& os, const Item& obj) {
        string dbar(30, '=');
        string bar(30, '-');

        os << dbar << endl;
        os << "名称: " << obj.name << "\t価格: " << obj.price << endl;
        os << bar << endl;
        os << "Recipe Information" << endl;
        os << bar << endl;
        os << obj.recipe;
        os << dbar << endl;
        return os;
    }
    
    /**
     *  商品を提供する
     *
     *  @return 商品提供結果
     */
    int Supply();
    
    /**
     *  商品購入可能かチェックする
     *
     *  @return 商品購入可否
     */
    bool IsAvailable() const;
    
    /**
     *  必要な材料が残っているかどうかチェックする
     *
     *  @return 必要な材料が残っているかどうか
     */
    bool HasSufficientIngredients() const;
    
    /**
     *  商品名を取得する
     *
     *  @return 商品名
     */
    string GetName() const;
    
    /**
     *  商品の価格を取得する
     *
     *  @return 商品価格
     */
    int GetPrice() const;
    
    
private:
    CoffeeType::typeID coffee_type;
    string name;
    int price;
    Recipe recipe;
    const Pay& pay;
};

#endif /* defined(__MBVM__Item__) */
