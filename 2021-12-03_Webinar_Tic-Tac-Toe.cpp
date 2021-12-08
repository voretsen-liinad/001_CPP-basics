// 2021-12-03_Webinar_Tic-Tac-Toe.cpp 
// Tic-Tac-Toe (homework) - Webinar of December, 3, 2021
// Created by Daniil Nesterov (e-mail: maidanov1991@yandex.ru) 

#include <iostream> 
#include <random>  
#include <chrono>
#include <stdlib.h>

using namespace std;

//values for game field cells:  
enum class CellValues {
    EMPTY = '_',
    CROSS = 'x',
    ZERO = 'o'
};

//values for game statuses:
enum class GameStates {
    IN_PROGRESS, 
    CROSS_WON, 
    ZERO_WON, 
    DRAW
};

//struct for game:
#pragma pack (push, 1)
struct Game {
    CellValues Field[3][3];       //game field 3x3
    CellValues UserSign : 8;      //game sign of the user (8 bit)
    CellValues AISign : 8;        //game sign of the comuter (8 bit)
    bool UserMovesNow : 1;        //answer to the question "Is it the user's turn now?" (1 bit)
    uint16_t RemainingMoves : 4;  //answer to the question "How many moves are there now until the end of the game?" (4 bit) 
    GameStates GameState;         //current game status
};
#pragma pop 

//function to get random number
int32_t GetRandomNum(int32_t min, int32_t max) {
    const static auto seed = chrono::system_clock::now().time_since_epoch().count();  
    static mt19937_64 generator(seed); 
    uniform_int_distribution<int32_t>dis(min, max); 
    return dis(generator); 
}; 

//function to initialise a game struct
Game* InitGame(Game* game){
//game field initialisation:    
    for (uint16_t i{ 0 }; i < 3; i++)   
    {
        for (uint16_t j{ 0 }; j < 3; j++)
        {
            game->Field[i][j] = CellValues::EMPTY; 
        }
    }

//random initialisation of the players' signs   
    if (GetRandomNum(1, 1000) > 500)    
    {
        game->UserSign = CellValues::CROSS; 
        game->UserMovesNow = true; 
        game->AISign = CellValues::ZERO; 
    }
    else
    {
        game->UserSign = CellValues::ZERO; 
        game->UserMovesNow = false;
        game->AISign = CellValues::CROSS;
    }

//initialisation of the other game struct parts    
    game->RemainingMoves = 9; 
    game->GameState = GameStates::IN_PROGRESS; 
    return game; 
};

//function to print current game field
void PrintCurrentGameField(Game* game) {
    system("cls"); 
    cout << "    Tic-Tac-Toe   \n"
         << "   | 1 | 2 | 3 |\n"; 
    for (uint16_t i{ 0 }; i < 3; i++) 
    {
        cout << " " << i + 1 << " | " << static_cast<char>(game->Field[i][0]) << " | "
             << static_cast<char>(game->Field[i][1]) << " | " << static_cast<char>(game->Field[i][2]) << " |\n";
    }
    cout << "\n\n"; 
    if (game->UserSign == CellValues::CROSS)
    {
        cout << "Your sign: CROSS (go first)\n"
             << "Computer's sign: ZERO\n\n";
    }     
    else
    {
        cout << "Computer's sign: CROSS (goes first)\n"
             << "Your sign: ZERO\n\n";
    } 
}

//function to define current status of a game
GameStates CheckGameState(const Game* game) {
//check if there is already a minimum required number of moves for any game result:    
    if (game->RemainingMoves > 5)
        return GameStates::IN_PROGRESS;     

//check strings for win combinations:   
    for (uint16_t i{ 0 }; i < 3; i++)   
    {
        if ((game->Field[i][0] != CellValues::EMPTY) && (game->Field[i][0] == game->Field[i][1] && game->Field[i][0] == game->Field[i][2]))
        {
            if (game->Field[i][0] == CellValues::CROSS)
                return GameStates::CROSS_WON; 
            else 
                return GameStates::ZERO_WON;
        } 
    }

//check columns for win combinations:
    for (uint16_t j{ 0 }; j < 3; j++)  
    {
        if ((game->Field[0][j] != CellValues::EMPTY) && (game->Field[0][j] == game->Field[1][j] && game->Field[0][j] == game->Field[2][j]))
        {
            if (game->Field[0][j] == CellValues::CROSS)
                return GameStates::CROSS_WON;
            else
                return GameStates::ZERO_WON;
        }
    }
    
//check diagonals for win combinations:
    if ((game->Field[1][1] != CellValues::EMPTY) && (game->Field[1][1] == game->Field[0][0] && game->Field[1][1] == game->Field[2][2]))
    {
        if (game->Field[1][1] == CellValues::CROSS)
            return GameStates::CROSS_WON;
        else
            return GameStates::ZERO_WON;
    }
    if ((game->Field[1][1] != CellValues::EMPTY) && (game->Field[1][1] == game->Field[0][2] && game->Field[1][1] == game->Field[2][0]))
    {
        if (game->Field[1][1] == CellValues::CROSS)
            return GameStates::CROSS_WON;
        else
            return GameStates::ZERO_WON;
    }

//check for a draw:
    if (game->RemainingMoves == 0)
        return GameStates::DRAW;
    else 
        return GameStates::IN_PROGRESS; 
}

//function to display a result of a game (the game's status must not be "IN_PROGRESS")
void FinishGame(Game* game) {
    if (game->GameState == GameStates::DRAW)
    {
        cout << "Draw!\n\n";
    }
    else if (((game->UserSign == CellValues::CROSS) && (game->GameState == GameStates::CROSS_WON))
        || ((game->UserSign == CellValues::ZERO) && (game->GameState == GameStates::ZERO_WON)))
    {
        cout << "You won!\n\n";
    }
    else if (((game->AISign == CellValues::CROSS) && (game->GameState == GameStates::CROSS_WON))
        || ((game->AISign == CellValues::ZERO) && (game->GameState == GameStates::ZERO_WON)))
    {
        cout << "Computer won!\n\n";
    }
}

//function provides the user a current move in a game
void UserMove(Game* game) {  
//get from the user the coordinates for his current move in a game:   
    cout << "Please, enter the coordinates for your current move:\n"; 
    uint16_t x{ 0 };
    uint16_t y{ 0 }; 
    do
    {
     
     //get x-coordinate:    
        do
        {
            cout << "Enter X (1...3): ";
            cin >> x; 
            if (x < 1 || x > 3)
                cout << x << "X value should be 1, 2 or 3.\n";
            else break; 
        } while (x < 1 || x > 3);
     
     //get y-coordinate:     
        do 
        {
            cout << "Enter Y (1...3): ";
            cin >> y;
            if (y < 1 || y > 3)
                cout << "Y value should be 1, 2 or 3.\n";
            else break; 
        } while (y < 1 || y > 3);
     
     //check if the chosen cell of a game field is empty:   
        if (game->Field[y - 1][x - 1] != CellValues::EMPTY)
            cout << "The chosen cell is not empty. Please, choose an empty cell.\n"; 

    } while (game->Field[y - 1][x - 1] != CellValues::EMPTY);
    
//update current game's struct after the user's move:   
    game->Field[y - 1][x - 1] = game->UserSign;
    game->RemainingMoves--;
    game->UserMovesNow = false;
    game->GameState = CheckGameState(game); 
}

//AIMove1 - first move to the empty center cell
bool AIMove1(Game* game) {   
    if (game->RemainingMoves > 7 && game->Field[1][1] == CellValues::EMPTY)
    {
        game->Field[1][1] = game->AISign;
        game->RemainingMoves--;
        game->UserMovesNow = true;
        game->GameState = CheckGameState(game);
        return true;
    }
    else
        return false;
}

//AIMove2 - move to an empty cell to win
bool AIMove2(Game* game) {
    for (uint16_t i{ 0 }; i < 3; i++)
    {
        for (uint16_t j{ 0 }; j < 3; j++)
        {
            if (game->Field[i][j] == CellValues::EMPTY)
            {
                game->Field[i][j] = game->AISign;
                game->RemainingMoves--;
                GameStates PotentialGameState = CheckGameState(game);
                if (((game->AISign == CellValues::CROSS) && (PotentialGameState == GameStates::CROSS_WON))
                    || ((game->AISign == CellValues::ZERO) && (PotentialGameState == GameStates::ZERO_WON)))
                {
                    game->UserMovesNow = true;
                    game->GameState = CheckGameState(game);
                    return true;
                }
                game->Field[i][j] = CellValues::EMPTY;
                game->RemainingMoves++;
            }
        }
    }
    return false; 
}

//AIMove3 - move to an empty cell to prevent the user's win
bool AIMove3(Game* game) {
    for (uint16_t i{ 0 }; i < 3; i++)
    {
        for (uint16_t j{ 0 }; j < 3; j++)
        {
            if (game->Field[i][j] == CellValues::EMPTY)
            {
                game->Field[i][j] = game->UserSign;
                game->RemainingMoves--;
                GameStates PotentialGameState = CheckGameState(game);
                if (((game->UserSign == CellValues::CROSS) && (PotentialGameState == GameStates::CROSS_WON))
                    || ((game->UserSign == CellValues::ZERO) && (PotentialGameState == GameStates::ZERO_WON)))
                {
                    game->Field[i][j] = game->AISign;
                    game->UserMovesNow = true;
                    game->GameState = CheckGameState(game);
                    return true;
                }
                game->Field[i][j] = CellValues::EMPTY;
                game->RemainingMoves++;
            }
        }
    }
    return false; 
}

//help function to AIMove4 - check for any full non-empty line 
bool CheckForFullNonEmptyLine(const Game* game) {
    //check if there is already a minimum required number of moves for any full non-empty line on a game field:    
    if (game->RemainingMoves > 7)
        return false;

    //check strings for full line combination:   
    for (uint16_t i{ 0 }; i < 3; i++)
    {
        if ((game->Field[i][0] != CellValues::EMPTY) && (game->Field[i][1] != CellValues::EMPTY) && (game->Field[i][2] != CellValues::EMPTY))
            return true; 
    }

    //check columns for full line combination:
    for (uint16_t j{ 0 }; j < 3; j++)
    {
        if ((game->Field[0][j] != CellValues::EMPTY) && (game->Field[1][j] != CellValues::EMPTY) && (game->Field[2][j] != CellValues::EMPTY))
            return true;
    }

    //check diagonals for full line combination:
    if ((game->Field[1][1] != CellValues::EMPTY) && (game->Field[0][0] != CellValues::EMPTY) && (game->Field[2][2] != CellValues::EMPTY))
        return true;
    if ((game->Field[1][1] != CellValues::EMPTY) && (game->Field[0][2] != CellValues::EMPTY) && (game->Field[2][0] != CellValues::EMPTY))
        return true;

    return false;
}

//AIMove4 - random move to available corner cell 
bool AIMove4(Game* game) {
    if (game->Field[0][0] == CellValues::EMPTY || game->Field[0][2] == CellValues::EMPTY
        || game->Field[2][0] == CellValues::EMPTY || game->Field[2][2] == CellValues::EMPTY)
    {
        do {
            if ((game->Field[0][0] == CellValues::EMPTY) && (GetRandomNum(1, 1000) > 500))
            {
                game->Field[0][0] = game->AISign; 
                game->RemainingMoves--; 
                if ((game->RemainingMoves < 6) || !CheckForFullNonEmptyLine(game))
                {
                    game->UserMovesNow = true;
                    game->GameState = CheckGameState(game);
                    return true; 
                }
                game->Field[0][0] = CellValues::EMPTY; 
                game->RemainingMoves++;
            }
            else if ((game->Field[0][2] == CellValues::EMPTY) && (GetRandomNum(1, 1000) <= 500))
            {
                game->Field[0][2] = game->AISign;
                game->RemainingMoves--;
                if ((game->RemainingMoves < 6) || !CheckForFullNonEmptyLine(game))
                {
                    game->UserMovesNow = true;
                    game->GameState = CheckGameState(game);
                    return true;
                }
                game->Field[0][2] = CellValues::EMPTY;
                game->RemainingMoves++;
            }
            else if ((game->Field[2][0] == CellValues::EMPTY) && (GetRandomNum(1, 1000) > 500))
            {
                game->Field[2][0] = game->AISign;
                game->RemainingMoves--;
                if ((game->RemainingMoves < 6) || !CheckForFullNonEmptyLine(game))
                {
                    game->UserMovesNow = true;
                    game->GameState = CheckGameState(game);
                    return true;
                }
                game->Field[2][0] = CellValues::EMPTY;
                game->RemainingMoves++;
            }
            else if ((game->Field[2][2] == CellValues::EMPTY) && (GetRandomNum(1, 1000) <= 500))
            {
                game->Field[2][2] = game->AISign;
                game->RemainingMoves--;
                if ((game->RemainingMoves < 6) || !CheckForFullNonEmptyLine(game))
                {
                    game->UserMovesNow = true;
                    game->GameState = CheckGameState(game);
                    return true;
                }
                game->Field[2][2] = CellValues::EMPTY;
                game->RemainingMoves++;
            }
        } while (!game->UserMovesNow);
    }
    return false; 
}

//AIMove5 - random move to available non-corner cell
void AIMove5(Game* game) {
    do {
        if ((game->Field[0][1] == CellValues::EMPTY) && (GetRandomNum(1, 1000) > 500))
        {
            game->Field[0][1] = game->AISign;
            game->UserMovesNow = true; 
        }
        else if ((game->Field[1][0] == CellValues::EMPTY) && (GetRandomNum(1, 1000) <= 500))
        {
            game->Field[1][0] = game->AISign;
            game->UserMovesNow = true;
        }
        else if ((game->Field[1][2] == CellValues::EMPTY) && (GetRandomNum(1, 1000) > 500))
        {
            game->Field[1][2] = game->AISign;
            game->UserMovesNow = true;
        }
        else if ((game->Field[2][1] == CellValues::EMPTY) && (GetRandomNum(1, 1000) <= 500))
        {
            game->Field[2][1] = game->AISign;
            game->UserMovesNow = true;
        }
    } while (!game->UserMovesNow);
    game->RemainingMoves--;
    game->GameState = CheckGameState(game);
}

//function providøòï the computer a current move in a game
void AIMove(Game* game) {
    if (!AIMove1(game))
    {
        if (!AIMove2(game))
        {
            if (!AIMove3(game))
            {
                if (!AIMove4(game))
                    AIMove5(game);
            }
        }
    }
}


int main()
{
    char answer{ ' ' };
    do
    {
        Game* CurrentGame = new (nothrow) Game;
        CurrentGame = InitGame(CurrentGame);
        PrintCurrentGameField(CurrentGame);

        uint16_t i;
        if (CurrentGame->UserMovesNow)
            i = 0;
        else
            i = 1;

        for (i; CheckGameState(CurrentGame) == GameStates::IN_PROGRESS && CurrentGame->RemainingMoves > 0; i++)
        {
            if (i % 2 == 0)
                UserMove(CurrentGame);
            else
                AIMove(CurrentGame);
            PrintCurrentGameField(CurrentGame);
        }
        if (CheckGameState(CurrentGame) == GameStates::DRAW)
            PrintCurrentGameField(CurrentGame);

        FinishGame(CurrentGame); 

        delete CurrentGame;
        CurrentGame = nullptr; 

        cout << "\n\nWould you like to play again? If yes, enter \"y\": "; 
        cin >> answer; 
    } while (answer == 'y' || answer == 'Y'); 
    
    cout << "\n\n"; 

    return 0; 
}