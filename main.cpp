#include <iostream>
#include <ctime>
using namespace std;

const int BOARD_SIZE = 10;

struct Ship {
    int length;
    int x;
    int y;
    bool horizontal;
    bool isSunk;
};

struct Board {
    char board[BOARD_SIZE][BOARD_SIZE];
    Ship ships[10];
};

void initBoard(Board &board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board.board[i][j] = '.';
        }
    }

    for (int i = 0; i < 5; i++) {
        board.ships[i].isSunk = false;
    }
}

void printBoard(const Board &board) {
    cout << "\t";
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << i + 1 << "\t";
    }
    cout << "\n";

    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << static_cast<char>('A' + i) << "\t";
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board.board[i][j] << "\t";
        }
        cout << "\n";
    }
}

bool isShipHit(const Ship &ship, int x, int y) {
    if (ship.horizontal) {
        return ship.x <= x && x < ship.x + ship.length && ship.y == y;
    } else {
        return ship.y <= y && y < ship.y + ship.length && ship.x == x;
    }
}

bool isGameOver(const Board &board) {
    for (int i = 0; i < 5; i++) {
        if (board.ships[i].isSunk) {
            return false;
        }
    }
    return true;
}

bool isShipSunk(Ship &ship, Board &board) {
    for (int i = 0; i < ship.length; i++) {
        if (!isShipHit(ship, ship.horizontal ? ship.x + i : ship.x,
                       ship.horizontal ? ship.y : ship.y + i)) {
            return false;
        }
    }
    ship.isSunk = true;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board.board[i][j] == 'X' && !isShipHit(ship, i, j)) {
                return false;
            }
        }
    }
    return true;
}

void placeShip(Board &board) {
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        bool horizontal = rand() % 2 == 0;
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;
        int length = 4 - i;
        bool valid = true;
        if (horizontal) {
            if (x + length > BOARD_SIZE) {
                valid = false;
            } else {
                for (int j = x; j < x + length; j++) {
                    if (board.board[j][y] != '.') {
                        valid = false;
                        break;
                    }
                }
            }
        } else {
            if (y + length > BOARD_SIZE) {
                valid = false;
            } else {
                for (int j = y; j < y + length; j++) {
                    if (board.board[x][j] != '.') {
                        valid = false;
                        break;
                    }
                }
            }
        }
        if (valid) {  // если корабль можно поставить
            for (int j = 0; j < length; j++) {  // по его длине
                if (horizontal) {  // если он горизонтальный
                    board.board[x + j][y] = static_cast<char>(254);  // заполняем клетки горизонтально
                } else {  // иначе
                    board.board[x][y + j] = static_cast<char>(254);  // заполнить клетки вертикально (j увеличивается)
                }
            }
            board.ships[i] = {length, x, y, horizontal, false}; // добавляю в массив новый корабль
        } else {
            i--;
        }
    }
}

bool isValidMove(const Board &board, int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return false;
    }
    return board.board[x][y] == '.' || board.board[x][y] == static_cast<char>(254);
}


int main() {
    Board player;
    initBoard(player);
    placeShip(player);

    printBoard(player);
    return 0;
}