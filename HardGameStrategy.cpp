//
//  HardGameStrategy.cpp
//  Learn
//
//  Created by Alexander Khotyanov on 1/21/14.
//  Copyright (c) 2014 Alexander Khotyanov. All rights reserved.
//

#include "HardGameStrategy.h"

int HardGameStrategy::pick_available_position(Board& board, int** winning)
{
    std::vector<int> avail_pos;
    board.get_available_positions(avail_pos);
    
    // Pick a winning combination
    for (int i=0; i!=8; ++i)
    {
        int* pos = winning[i];
        char p1 = board.position(0);
        char p2 = board.position(1);
        char p3 = board.position(2);
        
        if (p1 == '0' && p2 == '0' && p3 == '_') return pos[2];
        if (p1 == '0' && p2 == '_' && p3 == '0') return pos[1];
        if (p1 == '_' && p2 == '0' && p3 == '0') return pos[0];
    }
    
    // Block opponent from winning
    for (int i=0; i!=8; ++i)
    {
        int* pos = winning[i];
        char p1 = board.position(0);
        char p2 = board.position(1);
        char p3 = board.position(2);
        
        if (p1 == 'X' && p2 == 'X' && p3 == '_') return pos[2];
        if (p1 == 'X' && p2 == '_' && p3 == 'X') return pos[1];
        if (p1 == '_' && p2 == 'X' && p3 == 'X') return pos[0];
    }
    
    // Choose middle if available
    if (board.position(board.center_position()) == '_')
        return board.center_position();
    
    // Remove Bad Positions from available positions
    for (int i=0; i!=8; ++i)
    {
        int* pos = winning[i];
        char p1 = board.position(0);
        char p2 = board.position(1);
        char p3 = board.position(2);
        
        if (p1 == 'X' && p2 == '0' && p3 == '_' && avail_pos.size() > 1)
            avail_pos.erase(std::remove(avail_pos.begin(), avail_pos.end(), pos[2]), avail_pos.end());
        
        if (p1 == '0' && p2 == 'X' && p3 == '_' && avail_pos.size() > 1)
            avail_pos.erase(std::remove(avail_pos.begin(), avail_pos.end(), pos[2]), avail_pos.end());
        
        
        if (p1 == 'X' && p2 == '_' && p3 == '0' && avail_pos.size() > 1)
            avail_pos.erase(std::remove(avail_pos.begin(), avail_pos.end(), pos[1]), avail_pos.end());
        
        if (p1 == '0' && p2 == '_' && p3 == 'X' && avail_pos.size() > 1)
            avail_pos.erase(std::remove(avail_pos.begin(), avail_pos.end(), pos[1]), avail_pos.end());
        
        
        if (p1 == '_' && p2 == 'X' && p3 == '0' && avail_pos.size() > 1)
            avail_pos.erase(std::remove(avail_pos.begin(), avail_pos.end(), pos[0]), avail_pos.end());
        
        if (p1 == '_' && p2 == '0' && p3 == 'X' && avail_pos.size() > 1)
            avail_pos.erase(std::remove(avail_pos.begin(), avail_pos.end(), pos[0]), avail_pos.end());
    }
    
    // Select a random position from available positions
    return avail_pos[rand() % avail_pos.size()];
    
    throw "no more space on the board";
}