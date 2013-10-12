//
//  dao_recipe.h
//  InterprocessCommunication
//
//  Created by ogsh on 2013/10/03.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef InterprocessCommunication_dao_recipe_h
#define InterprocessCommunication_dao_recipe_h

#include <map>
#include <iostream>
#include "Util.h"
#include "CSV.h"

using namespace std;

/**
 *  コーヒーの種類
 */
namespace mbvm {
    /**
     *  コーヒーの種類
     */
    enum CoffeeType {
        MARUKO = 301,       ///< マルコブレンド
        SPECIAL = 302,      ///< スペシャルブレンド
        CAPPUCCINO = 303    ///< カプチーノ
    };


    /**
     *  レシピ情報
     */
    typedef struct recipe_info {
        int bean;               ///< コーヒー豆分量
        int sugar;              ///< 砂糖分量
        int milk;               ///< ミルク分量
        int water;              ///< 水分量
    } RECIPE_INFO;

    /**
     *  レシピDAO
     */
    class DaoRecipe {
    public:
        /**
         *  初期化
         *
         *  @param recipe_file_path レシピ情報が記述されたファイルへのパス
         */
        static void Initialize(const string& recipe_file_path) {
            CoffeeType coffee_types[3] = {CoffeeType::MARUKO, CoffeeType::SPECIAL, CoffeeType::CAPPUCCINO};
            CSV csv(recipe_file_path, ',');

            recipe_info.clear();
            for(int j = 0; j < csv.Rows(); ++j) {
                string name = csv.At(0, 0);
                int bean = Util::String::StrToNum<int>(csv.At(1, j));
                int milk = Util::String::StrToNum<int>(csv.At(2, j));
                int sugar = Util::String::StrToNum<int>(csv.At(3, j));
                int water = Util::String::StrToNum<int>(csv.At(4, j));
                RECIPE_INFO tmp_recipe_info = {bean, milk, sugar, water};
                recipe_info.insert(make_pair(coffee_types[j], tmp_recipe_info));
            }
        }
        
        /**
         *  レシピ情報を取得する
         *
         *  @param coffee_type コーヒーの種類
         *
         *  @return レシピ情報
         */
        static const RECIPE_INFO& Get(CoffeeType coffee_type) {
            return recipe_info[coffee_type];
        }

    private:
        static map<CoffeeType, RECIPE_INFO> recipe_info;
    };

    //RECIPE_INFO DaoRecipe::recipe_info[3] = {
    //    {20,  0,  0, 300},
    //    {20,  5,  5, 200},
    //    {20, 30, 40, 200}
    //};

}

#endif
