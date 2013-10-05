//
//  Receipt.h
//  MBVM
//
//  Created by ogsh on 2013/10/06.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef __MBVM__Receipt__
#define __MBVM__Receipt__

#include <iostream>
#include "Item.h"
#include "Util.h"

/**
 *  商品売り上げ記録
 */
class Receipt {
public:
    /**
     *  デフォルトコンストラクタ
     */
    Receipt();
    
    /**
     *  引数付きコンストラクタ
     */
    Receipt(const Item& item);
    
    /**
     *  出力用シフト演算子オーバーロード
     *
     *  @param os  出力先参照
     *  @param obj 自己参照
     *
     *  @return 出力先参照
     */
    friend ostream& operator<<(ostream& os, const Receipt& obj);
    
private:
    DATE date;      ///< 売り上げ日時
    Item item;      ///< 商品
};

#endif /* defined(__MBVM__Receipt__) */
