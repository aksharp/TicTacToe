//// command line build
//// clang++ -std=c++11 main.cpp -o TicTacToe
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <boost/algorithm/string.hpp>
//
//#define ANSI_COLOR_RED     "\x1b[31m"
//#define ANSI_COLOR_GREEN   "\x1b[32m"
//#define ANSI_COLOR_YELLOW  "\x1b[33m"
//#define ANSI_COLOR_BLUE    "\x1b[34m"
//#define ANSI_COLOR_MAGENTA "\x1b[35m"
//#define ANSI_COLOR_CYAN    "\x1b[36m"
//#define ANSI_COLOR_RESET   "\x1b[0m"
//
///*
// BOARD:
// row 1:  0, 1, 2
// row 2:  3, 4, 5
// row 3:  6, 7, 8
// */
//
//char board[9];
//
///*
// WIN:
// 0, 1, 2
// 3, 4, 5
// 6, 7, 8
// 0, 3, 6
// 1, 4, 7
// 2, 5, 8
// 0, 4, 8
// 2, 4, 6
// */
//
//int* winning[8];
//
//enum class GameMode { PLAYER_VS_PLAYER, COMPUTER_VS_PLAYER };
//enum class Level { EASY, HARD };
//GameMode game_mode;
//Level level;
//
//char winner()
//{
//    for (int i=0; i!=8; ++i)
//    {
//        int* pos = winning[i];
//        if ( board[pos[0]] != '_'
//            && board[pos[1]] != '_'
//            && board[pos[2]] != '_'
//            && board[pos[0]] == board[pos[1]]
//            && board[pos[1]] == board[pos[2]])
//        {
//            return board[pos[0]];
//        }
//    }
//    return '_';
//}
//
//void print_positions()
//{
//    std::cout << "Board Positions: \n";
//    for (int i=0; i != 9; ++i)
//    {
//        std::cout << " " << i;
//        if (i == 2) std::cout << "\n";
//        if (i == 5) std::cout << "\n";
//    }
//    std::cout << "\n";
//}
//
//void print_board()
//{
//    for (int i=0; i != 9; ++i)
//    {
//        switch (board[i])
//        {
//            case 'X':
//                printf(ANSI_COLOR_RED     " X "     ANSI_COLOR_RESET);
//                break;
//
//            case '0':
//                printf(ANSI_COLOR_YELLOW     " 0 "     ANSI_COLOR_RESET);
//                break;
//
//            case '_':
//                printf(ANSI_COLOR_GREEN     " - "     ANSI_COLOR_RESET);
//                break;
//                
//            default:
//                break;
//        }
//        
//        if (i == 2) std::cout << "\n";
//        if (i == 5) std::cout << "\n";
//    }
//    std::cout << "\n\n";
//}
//
//void turn(int position, char player)
//{
//    if (board[position] == 'X' || board[position] == '0')
//    {
//        auto err =  "\n*** Invalid Position ***\n"
//                    "Position " + std::to_string(position) +
//                    " is taken by player " + board[position] + "\n"
//                    "Please enter a number between 0 and 8: ";
//        throw err.c_str();
//    }
//    else
//    {
//        board[position] = player;
//        print_board();
//    }
//}
//
//void print_game_result()
//{
//    char w = winner();
//    if (w != '_')
//    {
//        printf("%s WINS!\n",
//           game_mode == GameMode::COMPUTER_VS_PLAYER && w == '0'
//                ? "Computer"
//                : std::string("Player ").append(std::string(1, w)).c_str());
//    }
//    else
//    {
//        printf("The game is a tie. \n");
//    }
//}
//
//void clear_board()
//{
//    std::fill_n(board, 9, '_');
//}
//
//bool is_game_finished(char* board)
//{
//    for (int i=0; i != 9; ++i)
//    {
//        if (board[i] == '_')
//        {
//            return false;
//        }
//    }
//    return true;
//}
//
//void process_user_input(char player)
//{
//    std::string input;
//    int pos;
//    
//    while(std::cin >> input)
//    {
//        try
//        {
//            pos = std::stoi(input);
//            
//            if (pos < 0 || pos > 8)
//            {
//                throw  "\n*** Invalid Position ***\n"
//                "Position is out of range\n"
//                "Please enter a number between 0 and 8: ";
//            }
//            else
//            {
//                turn(pos, player);
//                break;
//            }
//        }
//        catch (const char* msg)
//        {
//            printf("%s", msg);
//        }
//        catch(...)
//        {
//            printf("\n*** Invalid Position ***\n"
//                   "Please enter a number between 0 and 8: ");
//        }
//    }
//}
//
//GameMode get_game_mode()
//{
//    printf(
//            "0 = Player vs Player\n"
//            "1 = Computer vs Player\n\n"
//            "Please choose a game mode: (0 or 1) "
//           );
//    
//    std::string input;
//    int mode;
//    
//    while(std::cin >> input)
//    {
//        try
//        {
//            mode = std::stoi(input);
//            
//            if (mode < 0 || mode > 1)
//            {
//                throw "err";
//            }
//            else
//            {
//                switch (mode) {
//                    case 0:
//                        return GameMode::PLAYER_VS_PLAYER;
//                    case 1:
//                        return GameMode::COMPUTER_VS_PLAYER;
//                }
//            }
//        }
//        catch(...)
//        {
//            printf("No such game mode\nPlease enter 0 or 1: ");
//        }
//    }
//    throw "Game Mode Errored Oout";
//}
//
//void set_avail_pos(std::vector<int>& avail_pos)
//{
//    for (int i=0; i != 9; ++i)
//    {
//        if (board[i] == '_') avail_pos.push_back(i);
//    }
//}
//
//int pick_avail_num()
//{
//    std::vector<int> avail_pos;
//    set_avail_pos(avail_pos);
//    
//    if (avail_pos.size() > 0)
//        return avail_pos[rand() % avail_pos.size()];
//        
//    throw "no more space on the board";
//}
//
//int smart_pick_avail_num()
//{
//    std::vector<int> avail_pos;
//    set_avail_pos(avail_pos);
//    
//    // Pick a winning combination
//    for (int i=0; i!=8; ++i)
//    {
//        int* pos = winning[i];
//        char p1 = board[pos[0]];
//        char p2 = board[pos[1]];
//        char p3 = board[pos[2]];
//        
//        if (p1 == '0' && p2 == '0' && p3 == '_') return pos[2];
//        if (p1 == '0' && p2 == '_' && p3 == '0') return pos[1];
//        if (p1 == '_' && p2 == '0' && p3 == '0') return pos[0];
//    }
//    
//    // Block opponent from winning
//    for (int i=0; i!=8; ++i)
//    {
//        int* pos = winning[i];
//        char p1 = board[pos[0]];
//        char p2 = board[pos[1]];
//        char p3 = board[pos[2]];
//        
//        if (p1 == 'X' && p2 == 'X' && p3 == '_') return pos[2];
//        if (p1 == 'X' && p2 == '_' && p3 == 'X') return pos[1];
//        if (p1 == '_' && p2 == 'X' && p3 == 'X') return pos[0];
//    }
//    
//    // Choose middle if available
//    if (board[4] == '_') return 4;
//    
//    // Remove Bad Positions from available positions
//    for (int i=0; i!=8; ++i)
//    {
//        int* pos = winning[i];
//        char p1 = board[pos[0]];
//        char p2 = board[pos[1]];
//        char p3 = board[pos[2]];
//        
//        if (p1 == 'X' && p2 == '0' && p3 == '_' && avail_pos.size() > 1)
//            avail_pos.erase(std::remove(avail_pos.begin(), avail_pos.end(), pos[2]), avail_pos.end());
//        
//        if (p1 == '0' && p2 == 'X' && p3 == '_' && avail_pos.size() > 1)
//            avail_pos.erase(std::remove(avail_pos.begin(), avail_pos.end(), pos[2]), avail_pos.end());
//        
//        
//        if (p1 == 'X' && p2 == '_' && p3 == '0' && avail_pos.size() > 1)
//            avail_pos.erase(std::remove(avail_pos.begin(), avail_pos.end(), pos[1]), avail_pos.end());
//        
//        if (p1 == '0' && p2 == '_' && p3 == 'X' && avail_pos.size() > 1)
//            avail_pos.erase(std::remove(avail_pos.begin(), avail_pos.end(), pos[1]), avail_pos.end());
//        
//        
//        if (p1 == '_' && p2 == 'X' && p3 == '0' && avail_pos.size() > 1)
//            avail_pos.erase(std::remove(avail_pos.begin(), avail_pos.end(), pos[0]), avail_pos.end());
//        
//        if (p1 == '_' && p2 == '0' && p3 == 'X' && avail_pos.size() > 1)
//            avail_pos.erase(std::remove(avail_pos.begin(), avail_pos.end(), pos[0]), avail_pos.end());
//    }
//    
//    // Select a random position from available positions
//    return avail_pos[rand() % avail_pos.size()];
//    
//    throw "no more space on the board";
//}
//
//Level get_level()
//{
//    printf(
//           "0 = Easy\n"
//           "1 = Hard\n\n"
//           "Please choose a game level: (0 or 1) "
//           );
//    
//    std::string input;
//    int level;
//    
//    while(std::cin >> input)
//    {
//        try
//        {
//            level = std::stoi(input);
//            
//            if (level < 0 || level > 1)
//            {
//                throw "err";
//            }
//            else
//            {
//                switch (level) {
//                    case 0:
//                        return Level::EASY;
//                    case 1:
//                        return Level::HARD;
//                }
//            }
//        }
//        catch(...)
//        {
//            printf("No such level\nPlease enter 0 or 1: ");
//        }
//    }
//    throw "Level Errored Oout";
//}
//
//void play_game(int** winning)
//{
//    clear_board();
//    print_board();
//    
//    char player = '0';
//    
//    while(winner() == '_' && !is_game_finished(board))
//    {
//        player = player == 'X' ? '0' : 'X';
//        print_positions();
//        
//        if (game_mode == GameMode::COMPUTER_VS_PLAYER && player == '0')
//        {
//            printf("Computer goes\n");
//            int pos = level == Level::EASY
//            ? pick_avail_num()
//            : smart_pick_avail_num();
//            turn(pos, player);
//        }
//        else
//        {
//            printf("Player %c goes. Choose your position: ", player);
//            process_user_input(player);
//        }
//    }
//    
//        print_game_result();
//}
//
//int main_notOO(int argc, const char * argv[])
//{
//    // setup players
////    auto player1 = Player('0');
////    auto player2 = Player('X');
//    
//    // setup game options
//
//    game_mode = get_game_mode();
//    if (game_mode == GameMode::COMPUTER_VS_PLAYER)
//        level = get_level();
//    
//    size_t idx = 0;
//    winning[idx++] = (int[]){0,1,2};
//    winning[idx++] = (int[]){3,4,5};
//    winning[idx++] = (int[]){6,7,8};
//    winning[idx++] = (int[]){0,3,6};
//    winning[idx++] = (int[]){1,4,7};
//    winning[idx++] = (int[]){2,5,8};
//    winning[idx++] = (int[]){0,4,8};
//    winning[idx++] = (int[]){2,4,6};
//
//    
//    // start game
//    
//    std::string answer = "Yes";
//
//    while(answer.at(0) == 'Y')
//    {
//        play_game(winning);
//        printf("Do you want to play again? [Y]es or [N]o: ");
//        std::cin >> answer;
//        boost::to_upper(answer);
//    }
//    
//    return 0;
//}
