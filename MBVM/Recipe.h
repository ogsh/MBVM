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

class Recipe {
public:
    Recipe(const RECIPE_INFO& recipe_info);
    Recipe(const Recipe& obj);
    
    Recipe& operator=(const Recipe& obj);
    
private:
    int i1;
    int i2;
};


#endif /* defined(__InterprocessCommunication__recipe__) */