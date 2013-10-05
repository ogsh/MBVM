//
//  recipe.cpp
//  InterprocessCommunication
//
//  Created by ogsh on 2013/10/02.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#include "Recipe.h"

Recipe::Recipe(const RECIPE_INFO& recipe_info) : i1(recipe_info.i1), i2(recipe_info.i2) {
    
}

Recipe::Recipe(const Recipe& obj) : i1(obj.i1), i2(obj.i2) {
    
}

Recipe& Recipe::operator=(const Recipe& obj) {
    this->i1 = obj.i1;
    this->i2 = obj.i2;
    return *this;
}