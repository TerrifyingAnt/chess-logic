#include <Bishop.h>

Bishop::Bishop(Color color) : Figure('B') {
    this->color = color;
}

bool Bishop::canMove(int currentX, int currentY, int newX, int newY, Figure* board[8][8]) {
    // нужно проверить, что клетка (newX, newY) лежит на диагонали от клетки (currentX, currentY)
    // нужно проверить, что на пути от (currentX, currentY) до (newX, newY) нет фигур
    return (abs(newX - currentX) == abs(newY - currentY)) &&  
        (newX >= 0) && (newX < 8) && (newY >= 0) && (newY < 8) && board[newX][newY] == nullptr;
}

vector<pair<int, int>> Bishop::generateMoves(int x, int y, Figure* board[8][8]) {
    vector<pair<int, int>> moves;

    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {-1, 1, 1, -1};

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