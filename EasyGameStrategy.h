//
//  EasyGameStrategy.h
//  Learn
//
//  Created by Alexander Khotyanov on 1/21/14.
//  Copyright (c) 2014 Alexander Khotyanov. All rights reserved.
//

#ifndef __Learn__EasyGameStrategy__
#define __Learn__EasyGameStrategy__

#include <iostream>
#include "GameStrategy.h"

class EasyGameStrategy : public GameStrategy
{
public:
    EasyGameStrategy(){};
    ~EasyGameStrategy(){};
    int pick_available_position(Board& board, int** winning);
};

#endif /* defined(__Learn__EasyGameStrategy__) */
