#include <Queen.h>

Queen::Queen(Color color) : Figure('Q') {
    this->color = color;
}

bool Queen::canMove(int currentX, int currentY, int newX, int newY, Figure* board[8][8]) {
    // нужно проверить, что клетка (newX, newY) лежит на диагонали от клетки (currentX, currentY)
    // нужно проверить, что на пути от (currentX, currentY) до (newX, newY) нет фигур
    // нужно проверить, что newX и newY лежат на одной линии с currentX и currentY
    return (abs(newX - currentX) == abs(newY - currentY)) || 
        ((currentX == newX) || (currentY == newY)) &&  
        (newX >= 0) && (newX < 8) && (newY >= 0) && (newY < 8) && board[newX][newY] == nullptr;
}

vector<pair<int, int>> Queen::generateMoves(int x, int y, Figure* board[8][8]) {
    vector<pair<int, int>> moves;

    int dx[8] = {-1, -1, 1, 1, -1, 0, 0, 1};
    int dy[8] = {-1, 1, 1, -1, 0, -1, 1, 0};

    for (int i = 0; i < 8; i++) {
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