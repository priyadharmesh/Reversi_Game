// Standard (system) header files
#include <iostream>
#include <cstdlib>
#include "ReversiBoard.h"
#include <array>

// Add more standard header files as required
// #include <string>

using namespace std;

// Main program

int main() {
    ReversiBoard board;
    ReversiConsoleView console_view(board);

    while (true) {
        console_view.print_board();
        int player, row, col;
        cout << "Enter player (1 or 2): ";
        cin >> player;
        cout << "Enter row: ";
        cin >> row;
        cout << "Enter column: ";
        cin >> col;

        if (board.set_field_state(row, col, player)) {
            std::cout << "Move successful" << std::endl;
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    return 0;
}
