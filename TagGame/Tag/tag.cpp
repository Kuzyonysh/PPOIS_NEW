/**
 * @file tag.cpp
 * @brief Реализация класса Game, отвечающего за игровую логику "Пятнашек".
 */

#include "Header.h"


 /**
  * @brief Конструктор: создаёт поле и перемешивает его.
  */
Game::Game() {
    fill();
    change();
}

int Game::GetEmptyRow() const { return empty_row; }
int Game::GetEmptyCol() const { return empty_col; }
/**
 * @brief Заполняет поле числами от 1 до 15, последняя клетка — пустая (0).
 */
void Game::fill() {
    int n = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (n <= 15) {
                field[i][j] = n++;
            }
            else {
                field[i][j] = 0;
                empty_row = i;
                empty_col = j;
            }
        }
    }
}
/**
 * @brief Перемешивает поле случайным образом до тех пор, пока оно остаётся решаемым.
 */
void Game::change() {
    int arr[16];
    int k = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            arr[k++] = field[i][j];

    // перемешивание массива
    do {
        for (int i = 0; i < 16; i++) {
            int j = rand() % 16;
            swap(arr[i], arr[j]);
        }
    } while (!isSolvable(arr));

    k = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            field[i][j] = arr[k];
            if (arr[k] == 0) {
                empty_row = i;
                empty_col = j;
            }
            k++;
        }
}
/**
 * @brief Проверяет, можно ли решить текущее расположение фишек.
 *
 * Алгоритм основан на подсчёте инверсий и положении пустой клетки.
 */
bool Game::isSolvable(int arr[]) {
    int inversion = 0;
    for (int i = 0; i < 16; i++) {
        if (arr[i] == 0) continue;
        for (int j = i + 1; j < 16; j++) {
            if (arr[j] != 0 && arr[i] > arr[j])
                inversion++;
        }
    }
    int zero_index = -1;
    for (int i = 0; i < 16; i++)
        if (arr[i] == 0)
        {
            zero_index = i; break;
        }
    int row_zero = 4 - (zero_index / 4);
    return (inversion + row_zero) % 2 == 1;
}
/**
 * @brief Совершает ход в заданном направлении, если возможно.
 */
bool Game::move(char direction) {
    int new_r = empty_row;
    int new_c = empty_col;

    if (direction == 'W' || direction == 'w') new_r--;
    else if (direction == 'S' || direction == 's') new_r++;
    else if (direction == 'D' || direction == 'd') new_c++;
    else if (direction == 'A' || direction == 'a') new_c--;

    if (new_r >= 0 && new_r < 4 && new_c >= 0 && new_c < 4) {
        swap(field[new_r][new_c], field[empty_row][empty_col]);
        empty_row = new_r;
        empty_col = new_c;
        return true;
    }
    return false;
}
/**
 * @brief Проверяет, находится ли поле в собранном состоянии.
 */
bool Game::isRight() const {
    int number = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (!(i == 3 && j == 3)) {
                if (field[i][j] != number)
                    return false;
                number++;
            }
            else {
                if (field[i][j] != 0)
                    return false;
            }
        }
    }
    return true;
}
/**
 * @brief Возвращает указатель на строку игрового поля.
 */
int* Game::operator[](int row) {
    return field[row];
}
/**
 * @brief Выводит текущее состояние игрового поля в поток.
 */
ostream& operator<<(ostream& out, const Game& g) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (g.field[i][j] == 0)
                out << ".\t ";
            else
                out << g.field[i][j] << "\t";
        }
        out << "\n";
    }
    return out;
}

