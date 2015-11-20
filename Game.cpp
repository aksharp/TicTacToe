
#include "Game.h"

Game::Game(Player& player1, Player& player2, Board&  board,
           GameMode& game_mode, GameStrategy& game_strategy)
{
    _player1 = &player1;
    _player2 = &player2;
    _board = &board;
    _game_mode = game_mode;
    _game_strategy = &game_strategy;
    
    size_t idx = 0;
    winning_combinations[idx++] = (int[]){0,1,2};
    winning_combinations[idx++] = (int[]){3,4,5};
    winning_combinations[idx++] = (int[]){6,7,8};
    winning_combinations[idx++] = (int[]){0,3,6};
    winning_combinations[idx++] = (int[]){1,4,7};
    winning_combinations[idx++] = (int[]){2,5,8};
    winning_combinations[idx++] = (int[]){0,4,8};
    winning_combinations[idx++] = (int[]){2,4,6};
}

Game::~Game()
{
    winning_combinations = nullptr;
}

void Game::process_user_input(Player* player)
{
    std::string input;
    int pos;
    
    while(std::cin >> input)
    {
        try
        {
            pos = std::stoi(input);
            
            if (pos < 0 || pos > 8)
            {
                throw  "\n*** Invalid Position ***\n"
                "Position is out of range\n"
                "Please enter a number between 0 and 8: ";
            }
            else
            {
                _board->move(pos, *player);
                break;
            }
        }
        catch (const char* msg)
        {
            printf("%s", msg);
        }
        catch(...)
        {
            printf("\n*** Invalid Position ***\n"
                   "Please enter a number between 0 and 8: ");
        }
    }
}

void Game::play()
{
    _board->clear();
    _board->ui_print_board();
    
    auto player = _player1;
    
    while(_board->winner(winning_combinations) == '_' && _board->has_empty_position())
    {
        player = player->name() == _player1->name() ? _player1 : _player2;
        _board->ui_print_positions();
        
        if (_game_mode == GameMode::COMPUTER_VS_PLAYER
            && player->name() == _player1->name())
        {
            printf("Computer goes\n");
            int pos = _game_strategy->pick_available_position(*_board, winning_combinations);
            _board->move(pos, *player);
        }
        else
        {
            printf("Player %c goes. Choose your position: ", player->name());
            process_user_input(player);
        }
    }
    
    print_game_result();
}

void Game::print_game_result()
{
    char w = _board->winner(winning_combinations);
    if (w != '_')
    {
        printf("%s WINS!\n",
               _game_mode == GameMode::COMPUTER_VS_PLAYER && w == '0'
               ? "Computer"
               : std::string("Player ").append(std::string(1, w)).c_str());
    }
    else
    {
        printf("The game is a tie. \n");
    }
}