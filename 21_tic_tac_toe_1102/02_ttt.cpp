#include <iostream>
using namespace std;

void draw_board(char array[3][3]) {
    cout << "PLAYER - 1 [X]\t PLAYER - 2 [0]\n\n";
    cout << "\t\t      |      |      \n";
    cout << "\t\t   " << array[0][0] << "  |   " << array[0][1] << "  |   " << array[0][2] << "  \n";
    cout << "\t\t______|______|______\n";
    cout << "\t\t   " << array[1][0] << "  |   " << array[1][1] << "  |   " << array[1][2] << "  \n";
    cout << "\t\t______|______|______\n";
    cout << "\t\t   " << array[2][0] << "  |   " << array[2][1] << "  |   " << array[2][2] << "  \n";
    cout << "\t\t      |      |      \n";
}

void player_turn(char *turn, char array[3][3]) {
    if (*turn == 'X') {
        cout << "\nPlayer - 1 [X] turn: ";
    } else {
        cout << "\nPlayer - 2 [0] turn: ";
    }
    int choice_cell, row, col;
    cin >> choice_cell;
    switch (choice_cell) {  // этот свитч выбирает, в какое место на доске поставить крестик или нолик
        case 1: row = 0; col = 0; break;
        case 2: row = 0; col = 1; break;
        case 3: row = 0; col = 2; break;
        case 4: row = 1; col = 0; break;
        case 5: row = 1; col = 1; break;
        case 6: row = 1; col = 2; break;
        case 7: row = 2; col = 0; break;
        case 8: row = 2; col = 1; break;
        case 9: row = 2; col = 2; break;
        default:
            cout << "Invalid Move";
    }

    if (*turn == 'X' && array[row][col] != 'X' && array[row][col] != '0') {
        // подставим крестик, если место не занято
        array[row][col] = 'X';
        *turn = '0';
    } else if (*turn == '0' && array[row][col] != 'X' && array[row][col] != '0') {
        // подставим нолик, если место не занято
        array[row][col] = '0';
        *turn = 'X';
    } else {
        // если выбранная позиция уже занята каким-то символом
        cout << "Cell is already filled!\nChoose another!\n\n";
        player_turn(turn, array);  // вызываем функцию заново, чтобы сделать новый ход
    }
    draw_board(array);
}

bool game_over(bool *could_draw, char array[3][3]) {
    // проверили, что в строках и столбцах нет одинаковых фигур
    for (int i = 0; i < 3; i++) {
        if ((array[i][0] == array[i][1] && array[i][0] == array[i][2])  // если символы в строке совпадают
            || (array[0][i] == array[1][i] && array[0][i] == array[2][i])  // символы в столбце совпадают
                ) {
            return false;
        }
    }
    // проверили, что на диагоналях нет одинаковых фигур
    if ((array[0][0] == array[1][1] && array[0][0] == array[2][2]) ||
        (array[0][2] == array[1][1] && array[0][2] == array[2][0])) {
        return false;
    }

    // проверим, есть ли еще свободные места для фигур
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (array[i][j] != 'X' && array[i][j] != '0') {  // если на каком-то месте нет ни крестика, ни нолика
                return true;  // играть можно
            }
        }
    }
    // разрешаем рисовать поле
    *could_draw = true;
    return false;
}

int main_tic_tac_toe() {
    // массив для доски крестики-нолики
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    // переменные для игры
    char turn = 'X';
    bool draw = false;

    cout << "\t\t\tT I C -- T A C -- T O E -- G A M E\t\t\t";
    cout << "\n\t\t\t\tFOR 2 PLAYERS\t\t\t\t\n";

    while (game_over(&draw, board)) {
        draw_board(board);
        player_turn(&turn, board);
        game_over(&draw, board);
    }

    if (turn == 'X' && !draw) {
        cout << "\n\nCongrats! Player 2 has won the game!!!";
    } else if (turn == '0' && !draw) {
        cout << "\n\nCongrats! Player 1 has won the game!!!";
    } else {
        cout << "\n\nGame over!\n\n";
    }

    return 0;
}