//
//  recipe.h
//  InterprocessCommunication
//
//  Created by ogsh on 2013/10/02.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef __InterprocessCommunication__recipe__
#define __InterprocessCommunication__recipe__

#include <iostream>
#include "DaoRecipe.h"

using namespace std;

namespace mbvm {
    /**
     *  レシピ
     */
    class Recipe {
    public:
        /**
         *  コンストラクタ
         */
        Recipe(CoffeeType coffee_type);
        
        /**
         *  コピーコンストラクタ
         */
        Recipe(const Recipe& obj);

        /**
         *  代入演算子オーバーロード
         *
         *  @param obj 代入するRecipeオブジェクトへの参照
         *
         *  @return 自己参照
         */
        Recipe& operator=(const Recipe& obj);

        /**
         *  出力用シフト演算子オーバーロード
         *
         *  @param os  出力先への参照
         *  @param obj 出力されるRecipeオブジェクト
         *
         *  @return 出力先への参照
         */
        friend ostream& operator<<(ostream& os, const Recipe& obj) {
            os << "bean: " << obj.recipe_info.bean << endl;
            os << "milk: " << obj.recipe_info.milk << endl;
            os << "sugar: " << obj.recipe_info.sugar << endl;
            os << "water: " << obj.recipe_info.water << endl;
            
            return os;
        }
        
        /**
         *  レシピ情報に基づいてコーヒーを作る
         *
         *  @return 作業進捗度状況
         */
        int Make();
        
        /**
         *  必要な材料が残っているかどうかチェック
         *
         *  @return 必要な材料が残っているかどうか
         */
        bool HasSufficientIngredients() const;
        
        /**
         *  コーヒー作成作業の進捗状況を返す
         *
         *  @return 進捗
         */
        int GetProgress() const;
        
    private:
        RECIPE_INFO recipe_info;
        int progress;
    };
}

#endif /* defined(__InterprocessCommunication__recipe__) */