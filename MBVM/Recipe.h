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

class Recipe {
public:
    Recipe(CoffeeType::typeID coffee_type);
    Recipe(const Recipe& obj);
    
    Recipe& operator=(const Recipe& obj);
    
    friend ostream& operator<<(ostream& os, const Recipe& obj) {
        os << "bean: " << obj.recipe_info.bean << endl;
        os << "milk: " << obj.recipe_info.milk << endl;
        os << "sugar: " << obj.recipe_info.sugar << endl;
        os << "water: " << obj.recipe_info.water << endl;
        
        return os;
    }
    
    void Supply();
    
private:
    RECIPE_INFO recipe_info;
};


#endif /* defined(__InterprocessCommunication__recipe__) */