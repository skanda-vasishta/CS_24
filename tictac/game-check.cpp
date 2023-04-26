#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>

int main() {
    Board gameBoard;
    std::string line;
    int game_move = 0;
    char curr_player = ' ';
    
     while (std::getline(std::cin, line)) {
        try {
            Move move(line);
            gameBoard.play(move);
            game_move++;
            curr_player = gameBoard.get_player();
        } 
        catch (const ParseError& e) {
            std::cout << "Parsing error: " << e.what();
            return 1;
        } 
        catch (const InvalidMove& e) {
             std::cout << "Invalid move: " << e.what();
            return 2;
        }
    }

    if (game_move == 0) {
        std::cout << "Game in progress: New game." << std::endl;
    } else {
        for (int i = 0; i < game_move; i++) {
            if(curr_player == 'X'){
                std::cout << "Game in progress: O's turn" << std::endl;
                curr_player = 'O';
            } else if (curr_player == 'O') {
                std::cout << "Game in progress: X's turn" << std::endl;
                curr_player = 'X';
            }

        }
    if (gameBoard.get_result() == 'X') {
        std::cout << "Game over: X wins." << std::endl;
    } else if (gameBoard.get_result() == 'O') {
        std::cout << "Game over: O wins." << std::endl;
    } else if (gameBoard.get_result() == 'D') {
        std::cout << "Game over: Draw." << std::endl;
    } 

    return 0;


}
}