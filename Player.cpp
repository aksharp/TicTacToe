//
//  Player.cpp
//  Learn
//
//  Created by Alexander Khotyanov on 1/20/14.
//  Copyright (c) 2014 Alexander Khotyanov. All rights reserved.
//

#include "Player.h"

Player::Player(char c)
{
    player_char = c;
}

Player::~Player()
{

}

char Player::name()
{
    return player_char;
}

bool Player::is_winner(char* board, int** winning)
{
    char w = winning_char(board, winning);
    return w != '_' && w== player_char;
}

char Player::winning_char(char* board, int** winning)
{
    for (int i=0; i!=8; ++i)
    {
        int* pos = winning[i];
        if ( board[pos[0]] != '_'
            && board[pos[1]] != '_'
            && board[pos[2]] != '_'
            && board[pos[0]] == board[pos[1]]
            && board[pos[1]] == board[pos[2]])
        {
            return board[pos[0]];
        }
    }
    return '_';
}

bool Player::operator==(const Player &other) const {
    return player_char == other.player_char;
}

bool Player::operator!=(const Player &other) const {
    return !(*this == other);
}