#include <Rook.h>

Rook::Rook(Color color) : Figure('R') {
    this->color = color;
}

bool Rook::canMove(int currentX, int currentY, int newX, int newY, Figure* board[8][8]) {
    // нужно проверить, что на линии между (currentX, currentY) и (newX, newY) нет фигур
    // нужно проверить, что newX и newY лежат на одной линии с currentX и currentY
    return (currentX == newX) || (currentY == newY) &&  
        (newX >= 0) && (newX < 8) && (newY >= 0) && (newY < 8) && board[newX][newY] == nullptr;
}

vector<pair<int, int>> Rook::generateMoves(int x, int y, Figure* board[8][8]) {
    vector<pair<int, int>> moves;

    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        while (canMove(x, y, newX, newY, board)) {
            moves.push_back({newX, newY});
            newX += dx[i];
            newY += dy[i];
        }
    }

    return moves;
}