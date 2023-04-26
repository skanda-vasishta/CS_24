#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>

int main() {
    Board gameBoard;
    std::string line;
    int game_move = 0;
    
     while (std::getline(std::cin, line)) {
        try {
            Move move(line);
            gameBoard.play(move);
            game_move++;
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
            std::cout << "Game in progress: " << (gameBoard.get_player() == 'X' ? "O's turn." : "X's turn.") << std::endl;
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