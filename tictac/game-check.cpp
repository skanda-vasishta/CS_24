#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>

int main() {
    Board gameBoard;
    std::string line;
    
     while (gameBoard.get_result() == ' ') {

        std::cout << "Game in progress: ";
        if (gameBoard.get_moves() == 0) {
            std::cout << "New game." << std::endl;
        } else {
            std::cout << (gameBoard.get_player() == 'X' ? "X's turn." : "O's turn.") << std::endl;
        }

        std::getline(std::cin, line);
        try {
            Move move(line);
            gameBoard.play(move);
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

    if (gameBoard.get_result() == 'X') {
        std::cout << "Game over: X wins." << std::endl;
    } else if (gameBoard.get_result() == 'O') {
        std::cout << "Game over: O wins." << std::endl;
    } else if (gameBoard.get_result() == 'D') {
        std::cout << "Game over: Draw." << std::endl;
    } 

    return 0;


}
