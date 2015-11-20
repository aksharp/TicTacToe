//
//  HardGameStrategy.h
//  Learn
//
//  Created by Alexander Khotyanov on 1/21/14.
//  Copyright (c) 2014 Alexander Khotyanov. All rights reserved.
//

#ifndef __Learn__HardGameStrategy__
#define __Learn__HardGameStrategy__

#include <iostream>
#include "GameStrategy.h"

class HardGameStrategy : public GameStrategy
{
public:
    HardGameStrategy(){};
    ~HardGameStrategy(){};
    int pick_available_position(Board& board, int** winning);
};

#endif /* defined(__Learn__HardGameStrategy__) */
