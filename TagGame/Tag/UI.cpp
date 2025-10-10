/**
 * @file UI.cpp
 * @brief Реализация класса UI для консольного управления игрой "Пятнашки".
 */

#include "Header.h"
 /**
  * @brief Конструктор класса UI.
  * @param game Ссылка на объект игры, с которым будет работать пользователь.
  */




UI::UI(Game& game) : game(game) {}

/**
 * @brief Runs the user interface for the game.
 *
 * Displays the game board, accepts user commands:
 * - W/S/A/D — move tiles;
 * - C — check the value of a cell;
 * - E — exit the game.
 */
void UI::start() {
    char choice;

    while (true) {
        cout << "\n-------------------------------\n";
        cout << game;
        cout << "\n-------------------------------\n";
        cout << "Commands:\n";
        cout << "W - up, S - down, A - left, D - right\n";
        cout << "C - check cell value, E - exit\n";
        cout << "Your move: ";
        

        if (!(cin >> choice)) {
            cout << "\nInput finished.\n";
            break;
        }

        if (choice == 'E' || choice == 'e') {
            cout << "You exited the game.\n";
            break;
        }
        else if (choice == 'C' || choice == 'c') {
            int row, col;
            cout << "Enter row number: ";
            if (!(cin >> row)) break;
            cout << "Enter column number: ";
            if (!(cin >> col)) break;

            if (row < 0 || row > 3 || col < 0 || col > 3) {
                cout << "Error: invalid coordinates!\n";
            }
            else {
                int value = game[row][col];
                cout << "Cell value [" << row << "][" << col << "] = " << value << "\n";
            }
        }
        else if (choice == 'W' || choice == 'w' ||
            choice == 'S' || choice == 's' ||
            choice == 'A' || choice == 'a' ||
            choice == 'D' || choice == 'd') {

            if (!game.move(choice)) {
                cout << "Move not possible!\n";
            }
            else if (game.isRight()) {
                cout << "\n" << game << endl;
                cout << "Congratulations! Puzzle solved!\n";
             
                break;
            }
        }
        else {
            cout << "Invalid command!\n";
        }
    }
}
