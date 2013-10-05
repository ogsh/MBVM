//
//  dao_recipe.h
//  InterprocessCommunication
//
//  Created by ogsh on 2013/10/03.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef InterprocessCommunication_dao_recipe_h
#define InterprocessCommunication_dao_recipe_h

typedef struct recipe_info {
    int i1;
    int i2;
} RECIPE_INFO;

class DaoRecipe {
public:
    static RECIPE_INFO recipe_info[2];
    
    static const RECIPE_INFO& Get(int id) {
        return recipe_info[id];
    }
    
    
};

RECIPE_INFO DaoRecipe::recipe_info[2] = {
    {3, 4},
    {5, 6}
};


#endif
