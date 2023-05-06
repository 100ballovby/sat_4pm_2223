#include <iostream>
#include <random>
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

    for (int i = 0; i < 10; i++) {
        board.ships[i].isSunk = false;
    }
}

void printBoard(const Board &board) {
    cout << "\t";
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << i << "\t";
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

bool isGameOver(Board &board) {
    bool finished;
    for (int i = 0; i < 10; i++) {
        if (board.ships[i].isSunk) {
            finished = true;
        } else {
            finished = false;
        }
    }
    return finished;
}

bool isShipSunk(Ship &ship, Board &board) {
    bool isHit = false;
    for (int i = 0; i < ship.length; i++) {
        if (!isShipHit(ship, ship.horizontal ? ship.x + i : ship.x,
                       ship.horizontal ? ship.y : ship.y + i)) {
            return false;
        }
        isHit = true;
    }
    if (isHit) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (ship.horizontal) {
                    if (board.board[i][j] == 'X' && !isShipHit(ship, i, j)) {
                        ship.isSunk = true;
                    }
                } else {
                    if (board.board[j][i] == 'X' && !isShipHit(ship, i, j)) {
                        ship.isSunk = true;
                    }
                }
            }
        }
        return true;
    } else {
        return false;
    }
}


void placeShip(Board &board) {
    const int numShips = 10;
    int shipsLength[numShips] = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
    int shipsLeft[numShips] = {4, 3, 2, 1, 2, 2, 2, 1, 1, 1};


    for (int i = 0; i < numShips; i++) {
        int length = shipsLength[i];
        bool valid = false;

        while (!valid) {
            bool horizontal = rand() % 2 == 0;
            int x = rand() % (BOARD_SIZE - length + 1);
            int y = rand() % (BOARD_SIZE - length + 1);

            // проверяем, что на всех клетках, которые занимает корабль, нет других кораблей
            bool hasCollision = false;
            for (int j = 0; j < length; j++) {
                if (horizontal && board.board[x + j][y] != '.') {
                    hasCollision = true;
                    break;
                }
                if (!horizontal && board.board[x][y + j] != '.') {
                    hasCollision = true;
                    break;
                }
            }

            if (hasCollision) {  // если корабль имеет пересечение с другими кораблями, то мы пропускаем итерацию и пытаемся поставить его в другое место
                continue;
            }

            // если корабль не пересекается ни с чем
            for (int j = 0; j < length; j++) {
                if (horizontal) {
                    board.board[x + j][y] = static_cast<char>(254);
                } else {
                    board.board[x][y + j] = static_cast<char>(254);
                }
            }

            // добавить корабль в массив кораблей на доске
            board.ships[i] = {length, x, y, horizontal, false};
            shipsLeft[i]--;
            valid = true;
        }
    }
}


bool isValidMove(const Board &board, int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return false;
    }
    return board.board[x][y] == '.' || board.board[x][y] == static_cast<char>(254);
}

void makeMove(Board &board) {
    string input;
    int x, y;

    do {
        cout << "Insert coordinates: ";
        cin >> input;
        x = input[0] - 'A';  // A (32) - A (32) = 0
        y = input[1] - '0';
    } while (!isValidMove(board, x, y));

    if (board.board[x][y] == static_cast<char>(254)) {
        for (int i = 0; i < 10; i++) {
            if (!board.ships[i].isSunk && isShipHit(board.ships[i], x, y)) {
                if (isShipSunk(board.ships[i], board)) {
                    cout << "You Sank my ship!" << endl;
                } else {
                    cout << "Hit!" << endl;
                }
                board.board[x][y] = 'X';
                return;
            }
        }
    }
    cout << "Miss!" << endl;
    board.board[x][y] = '-';
}


int main() {
    srand(time(NULL));
    Board playerBoard, computerBoard;
    initBoard(playerBoard);
    initBoard(computerBoard);
    placeShip(playerBoard);
    placeShip(computerBoard);

    cout << "player sunked ships: ";
    for (int i = 0; i < 10; i++) {
        cout << playerBoard.ships[i].isSunk << " ";
    }

    while (!isGameOver(playerBoard) && !isGameOver(computerBoard)) {
        cout << "Player board:\n";
        printBoard(playerBoard);
        makeMove(computerBoard);

        cout << "Computer board:\n";
        printBoard(computerBoard);
        makeMove(playerBoard);

    }

    if (isGameOver(playerBoard)) {
        cout << "Computer wins!" << endl;
    } else if (isGameOver(computerBoard)) {
        cout << "Player wins!" << endl;
    }
    return 0;
}