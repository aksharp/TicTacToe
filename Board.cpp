//
//  Board.cpp
//  Learn
//
//  Created by Alexander Khotyanov on 1/20/14.
//  Copyright (c) 2014 Alexander Khotyanov. All rights reserved.
//

#include "Board.h"

void Board::clear()
{
    std::fill_n(_board, 9, '_');
}

void Board::ui_print_positions()
{
    std::cout << "Board Positions: \n";
    for (int i=0; i != 9; ++i)
    {
        std::cout << " " << i;
        if (i == 2) std::cout << "\n";
        if (i == 5) std::cout << "\n";
    }
    std::cout << "\n";
}

void Board::ui_print_board()
{
    for (int i=0; i != 9; ++i)
    {
        switch (_board[i])
        {
            case 'X':
                printf(ANSI_COLOR_RED     " X "     ANSI_COLOR_RESET);
                break;
                
            case '0':
                printf(ANSI_COLOR_YELLOW     " 0 "     ANSI_COLOR_RESET);
                break;
                
            case '_':
                printf(ANSI_COLOR_GREEN     " - "     ANSI_COLOR_RESET);
                break;
                
            default:
                break;
        }
        
        if (i == 2) std::cout << "\n";
        if (i == 5) std::cout << "\n";
    }
    std::cout << "\n\n";
}

void Board::move(int position, Player& player)
{
    if (_board[position] == 'X' || _board[position] == '0')
    {
        auto err =  "\n*** Invalid Position ***\n"
        "Position " + std::to_string(position) +
        " is taken by player " + _board[position] + "\n"
        "Please enter a number between 0 and 8: ";
        throw err.c_str();
    }
    else
    {
        _board[position] = player.name();
    }
}

char Board::winner(int** winning_combination)
{
    for (int i=0; i!=8; ++i)
    {
        int* pos = winning_combination[i];
        if ( _board[pos[0]] != '_'
            && _board[pos[1]] != '_'
            && _board[pos[2]] != '_'
            && _board[pos[0]] == _board[pos[1]]
            && _board[pos[1]] == _board[pos[2]])
        {
            return _board[pos[0]];
        }
    }
    return '_';
}

bool Board::has_empty_position()
{
    for (int i=0; i != 9; ++i)
    {
        if (_board[i] == '_')
        {
            return false;
        }
    }
    return true;
}

void Board::get_available_positions(std::vector<int>& avail_pos)
{
    for (int i=0; i != 9; ++i)
    {
        if (_board[i] == '_') avail_pos.push_back(i);
    }

}