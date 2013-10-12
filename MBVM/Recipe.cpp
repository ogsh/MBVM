//
//  recipe.cpp
//  InterprocessCommunication
//
//  Created by ogsh on 2013/10/02.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#include "Recipe.h"

using namespace mbvm;

Recipe::Recipe(CoffeeType coffee_type) : recipe_info(DaoRecipe::Get(coffee_type)), progress(0) {
    
}

Recipe::Recipe(const Recipe& obj) : recipe_info(obj.recipe_info), progress(0) {
    
}

Recipe& Recipe::operator=(const Recipe& obj) {
    this->recipe_info = obj.recipe_info;
    return *this;
}

int Recipe::Make() {
    switch (this->progress) {
        case 0:
            cout << "水排出中" << endl;
            this->progress ++;
            break;
        case 1:
            cout << "ミルク排出中" << endl;
            this->progress ++;
        case 2:
            cout << "砂糖排出中" << endl;
            this->progress ++;
        case 3:
            cout << "コーヒードリップ中" << endl;
            this->progress ++;
        case 4:
            cout << "コーヒー完成" << endl;
            this->progress = 0;
        default:
            break;
    }
    
    return this->progress;
}

bool Recipe::HasSufficientIngredients() const {
    return true;
}

int Recipe::GetProgress() const {
    return this->progress;
}