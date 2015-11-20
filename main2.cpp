#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include "Board.h"
#include "GameMode.h"
#include "Level.h"
#include "Game.h"
#include "EasyGameStrategy.h"

GameMode get_game_mode()
{
    printf(
           "0 = Player vs Player\n"
           "1 = Computer vs Player\n\n"
           "Please choose a game mode: (0 or 1) "
           );
    
    std::string input;
    int mode;
    
    while(std::cin >> input)
    {
        try
        {
            mode = std::stoi(input);
            
            if (mode < 0 || mode > 1)
            {
                throw "err";
            }
            else
            {
                switch (mode) {
                    case 0:
                        return GameMode::PLAYER_VS_PLAYER;
                    case 1:
                        return GameMode::COMPUTER_VS_PLAYER;
                }
            }
        }
        catch(...)
        {
            printf("No such game mode\nPlease enter 0 or 1: ");
        }
    }
    throw "Game Mode Errored Oout";
}

Level get_level()
{
    printf(
           "0 = Easy\n"
           "1 = Hard\n\n"
           "Please choose a game level: (0 or 1) "
           );
    
    std::string input;
    int level;
    
    while(std::cin >> input)
    {
        try
        {
            level = std::stoi(input);
            
            if (level < 0 || level > 1)
            {
                throw "err";
            }
            else
            {
                switch (level) {
                    case 0:
                        return Level::EASY;
                    case 1:
                        return Level::HARD;
                }
            }
        }
        catch(...)
        {
            printf("No such level\nPlease enter 0 or 1: ");
        }
    }
    throw "Level Errored Oout";
}

int main(int argc, const char * argv[])
{
//    Level level;
    
    // setup board
    GameMode game_mode = get_game_mode();
    auto level = get_level();
    auto game_strategy = EasyGameStrategy();
    auto board = Board();
    auto player1 = Player('0');
    auto player2 = Player('X');

    auto game = Game(player1, player2, board, game_mode, game_strategy);

    
    // start game
    
    std::string answer = "Yes";
    
    while(answer.at(0) == 'Y')
    {
//        game.play();  //      play_game(winning);
        printf("Do you want to play again? [Y]es or [N]o: ");
        std::cin >> answer;
        boost::to_upper(answer);
    }
    
    return 0;
}
