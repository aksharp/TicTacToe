//
//  Board.h
//  Learn
//
//  Created by Alexander Khotyanov on 1/20/14.
//  Copyright (c) 2014 Alexander Khotyanov. All rights reserved.
//

#ifndef __Learn__Board__
#define __Learn__Board__

#include <iostream>
#include <vector>
#include "Player.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

class Board
{
    
public:
    Board(){};
    ~Board(){};
    
    void clear();
    void move(int position, Player& player);
    char winner(int** winning_combination);
    bool has_empty_position();
    void get_available_positions(std::vector<int>& avail_pos);
    char position(int position_number) { return _board[position_number]; }
    int center_position() { return 4; }
    
    void ui_print_positions();
    void ui_print_board();

    
private:
    char _board[9];

};

#endif /* defined(__Learn__Board__) */
