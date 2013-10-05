//
//  recipe.cpp
//  InterprocessCommunication
//
//  Created by ogsh on 2013/10/02.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#include "Recipe.h"

Recipe::Recipe(CoffeeType::typeID coffee_type) : recipe_info(DaoRecipe::Get(coffee_type)) {
    
}

Recipe::Recipe(const Recipe& obj) : recipe_info(obj.recipe_info) {
    
}

Recipe& Recipe::operator=(const Recipe& obj) {
    this->recipe_info = obj.recipe_info;
    return *this;
}

void Recipe::Make() {
    cout << "できました" << endl;
}

bool Recipe::HasSufficientIngredients() const {
    return true;
}