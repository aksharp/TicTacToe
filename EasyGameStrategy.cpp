//
//  EasyGameStrategy.cpp
//  Learn
//
//  Created by Alexander Khotyanov on 1/21/14.
//  Copyright (c) 2014 Alexander Khotyanov. All rights reserved.
//

#include "EasyGameStrategy.h"

int EasyGameStrategy::pick_available_position(Board& board, int** winning)
{
    std::vector<int> avail_pos;
    board.get_available_positions(avail_pos);
    
    if (avail_pos.size() > 0)
        return avail_pos[rand() % avail_pos.size()];
    
    throw "no more space on the board";
}