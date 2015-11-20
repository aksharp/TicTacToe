//
//  Player.h
//  Learn
//
//  Created by Alexander Khotyanov on 1/20/14.
//  Copyright (c) 2014 Alexander Khotyanov. All rights reserved.
//

#ifndef __Learn__Player__
#define __Learn__Player__

#include <iostream>

class Player
{
    
public:
    // constructor
    Player(char c);
    
    // destructor
    ~Player();
    
    // query
    bool is_winner(char* board, int** winning);
    char name();
    
private:
    // state
    char player_char;
    
    // command
    
    // query
    char winning_char(char* board, int** winning);
    bool operator==(const Player &other) const;
    bool operator!=(const Player &other) const;
    
};

#endif /* defined(__Learn__Player__) */
