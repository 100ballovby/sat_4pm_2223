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

bool isGameOver(Board &board) {
    for (int i = 0; i < 10; i++) {
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
    random_device rd;  // объявление генератора случайных чисел
    mt19937 gen(rd());  // для создания системы координат генерации
    uniform_int_distribution<> dist(0, BOARD_SIZE);  // распределение результатов генерации имежду 0 и длиной доски
    const int numShips = 10; // общее количество кораблей
    int shipsLength[numShips] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};  // массив кораблей
    int shipsLeft[numShips] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    for (int i = 0; i < numShips; i++) {
        int length = shipsLength[i];
        bool valid = false;

        while (!valid) {
            bool horizontal = rand() % 2 == 0;
            int x = dist(gen);
            int y = dist(gen);
            if (horizontal) {
                if (x + length > BOARD_SIZE) {
                    continue;
                } else {
                    valid = true;
                    for (int j = x; j < x + length; j++) {
                        if (board.board[j][y] != '.') {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        for (int j = x - 1; j <= x + length; j++) {
                            for (int k = y - 1; k <= y + 1; k++) {
                                if (j >= 0 && j < BOARD_SIZE && k >= 0 && k < BOARD_SIZE && board.board[j][k] != '.') {
                                    valid = false;
                                    break;
                                }
                            }
                        }
                    }
                }
            } else {
                if (y + length > BOARD_SIZE) {
                    continue;
                } else {
                    valid = true;
                    for (int j = y; j < y + length; j++) {
                        if (board.board[x][j] != '.') {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        for (int j = x - 1; j <= x + 1; j++) {
                            for (int k = y - 1; k <= y + length; k++) {
                                if (j >= 0 && j < BOARD_SIZE && k >= 0 && k < BOARD_SIZE && board.board[j][k] != '.') {
                                    valid = false;
                                    break;
                                }
                            }
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
                shipsLeft[i]--;
            }
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
        y = input[1] - '1';
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

    while (isGameOver(playerBoard) && isGameOver(computerBoard)) {
        cout << "Player board:\n";
        printBoard(playerBoard);
        makeMove(computerBoard);

        cout << "Computer board:\n";
        printBoard(computerBoard);
        makeMove(playerBoard);
    }
    return 0;
}