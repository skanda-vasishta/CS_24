#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>

int main() {
    Board gameBoard;
    std::string line;
    int game_move = 0;
    char curr_player = ' ';
    char prev_player = 'L';
    
     while (std::getline(std::cin, line)) {
        try {
            Move move(line);
            gameBoard.play(move);
            game_move++;
            prev_player = curr_player;
            curr_player = gameBoard.get_player();
            if (curr_player == prev_player) {
                throw InvalidMove("Same player moved twice in a row");
            }
        } 
        catch (const ParseError& e) {
            std::cout << "Parse error." <<std::endl ;
            return 1;
        } 
        catch (const InvalidMove& e) {
             std::cout << "Invalid move."<<std::endl ;
            return 2;
        }
    }

    if (game_move == 0) {
        std::cout << "Game in progress: New game." << std::endl;
    } else {
        if(curr_player == 'X' && game_move < 9 && !gameBoard.check_winner()){
            std::cout << "Game in progress: O's turn." << std::endl;
            curr_player = 'O';
        } else if (curr_player == 'O' && game_move < 9 && !gameBoard.check_winner()) {
            std::cout << "Game in progress: X's turn." << std::endl;
            curr_player = 'X';
        } else if (gameBoard.get_result() == 'X') {
            std::cout << "Game over: X wins." << std::endl;
        } else if (gameBoard.get_result() == 'O') {
            std::cout << "Game over: O wins." << std::endl;
        } else if (gameBoard.get_result() == 'D') {
            std::cout << "Game over: Draw." << std::endl;
        } 

    return 0;


}
}