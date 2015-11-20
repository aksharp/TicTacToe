//
//  GameStrategy.h
//  Learn
//
//  Created by Alexander Khotyanov on 1/21/14.
//  Copyright (c) 2014 Alexander Khotyanov. All rights reserved.
//

#ifndef __Learn__GameStrategy__
#define __Learn__GameStrategy__

#include <iostream>
#include "Board.h"

class GameStrategy
{
public:
    GameStrategy(){};
    ~GameStrategy(){};
    virtual int pick_available_position(Board& board, int** winning) = 0;
};

#endif /* defined(__Learn__GameStrategy__) */
