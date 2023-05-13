bool isShipHit(const Ship &ship, int x, int y) {
    if (ship.horizontal) {
        return ship.x <= x && x < ship.x + ship.length && ship.y == y;
    } else {
        return ship.y <= y && y < ship.y + ship.length && ship.x == x;
    }

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