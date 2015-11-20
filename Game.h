//
//  Game.h
//  Learn
//
//  Created by Alexander Khotyanov on 1/20/14.
//  Copyright (c) 2014 Alexander Khotyanov. All rights reserved.
//

#ifndef __Learn__Game__
#define __Learn__Game__

#include <iostream>
#include "GameMode.h"
#include "Player.h"
#include "Board.h"
#include "GameStrategy.h"
#include <vector>

class Game {
    
public:
    Game(Player& player1, Player& player2, Board& board,
         GameMode& game_mode, GameStrategy& game_strategy);
    ~Game();
    void play();

private:
    GameMode _game_mode;
    GameStrategy* _game_strategy;
    Player* _player1;
    Player* _player2;
    Board* _board;
    int** winning_combinations; //TODO: make static
    void process_user_input(Player* player);
    void print_game_result();
    
};


#endif /* defined(__Learn__Game__) */