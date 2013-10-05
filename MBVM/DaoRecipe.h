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

namespace CoffeeType {
    enum typeID {
        MARUKO = 301,
        SPECIAL = 302,
        CAPPUCCINO = 303
    };
}

typedef struct recipe_info {
    int bean;
    int sugar;
    int milk;
    int water;
} RECIPE_INFO;

/*
class RECIPE_INFO {
public:
    int bean;
    int sugar;
    int milk;
    int water;
    
    RECIPE_INFO() :
    bean(0), sugar(0), milk(0), water(0) {
    }
    
    RECIPE_INFO(int bean, int sugar, int milk, int water) :
    bean(bean), sugar(sugar), milk(milk), water(water) {
    }
    
    RECIPE_INFO(const RECIPE_INFO& obj) :
    bean(obj.bean), sugar(obj.sugar), milk(obj.milk), water(obj.water) {
        
    }
    
    RECIPE_INFO& operator=(const RECIPE_INFO& obj) {
        this->bean = obj.bean;
        this->sugar = obj.sugar;
        this->milk = obj.milk;
        this->water = obj.water;
        return *this;
    }
};
 */

class DaoRecipe {
public:
    static void Initialize(const string& recipe_file_path) {
        CoffeeType::typeID coffee_types[3] = {CoffeeType::MARUKO, CoffeeType::SPECIAL, CoffeeType::CAPPUCCINO};
        CSV csv(recipe_file_path, ',');

        recipe_info.clear();
        for(int j = 0; j < csv.Rows(); ++j) {
            string name = csv.At(0, 0);
            int bean = Util::StrToNum<int>(csv.At(1, j));
            int milk = Util::StrToNum<int>(csv.At(2, j));
            int sugar = Util::StrToNum<int>(csv.At(3, j));
            int water = Util::StrToNum<int>(csv.At(4, j));
            RECIPE_INFO tmp_recipe_info = {bean, milk, sugar, water};
            recipe_info.insert(make_pair(coffee_types[j], tmp_recipe_info));
        }
    }
    
    static const RECIPE_INFO& Get(CoffeeType::typeID coffee_type) {
        return recipe_info[coffee_type];
    }

private:
    static map<CoffeeType::typeID, RECIPE_INFO> recipe_info;
};

//RECIPE_INFO DaoRecipe::recipe_info[3] = {
//    {20,  0,  0, 300},
//    {20,  5,  5, 200},
//    {20, 30, 40, 200}
//};


#endif
