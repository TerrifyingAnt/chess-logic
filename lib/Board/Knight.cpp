#include<Knight.h>

Knight::Knight(Color color) : Figure('N') {
    this->color = color;
}

bool Knight::canMove(int currentX, int currentY, int newX, int newY, Figure* board[8][8]) {
    // нужно проверить, что клетка (newX, newY) лежит на расстоянии sqrt(5) от клетки (currentX, currentY)
    // нужно проверить, что клетка (newX, newY) не занята фигурой того же цвета
    return (abs(newX - currentX) == 2 && abs(newY - currentY) == 1) || (abs(newX - currentX) == 1 && abs(newY - currentY) == 2) &&  
        (newX >= 0) && (newX < 8) && (newY >= 0) && (newY < 8) && (board[newX][newY] == nullptr || board[newX][newY]->getColor() != this->getColor());
}

vector<pair<int, int>> Knight::generateMoves(int x, int y, Figure* board[8][8]) {
    // ходы, которые может совершить конь
    // конь может сделать ход в клетку, которая лежит на расстоянии sqrt(5) от текущей
    // если клетка занята фигурой противоположного цвета, то конь может съесть её
    vector<pair<int, int>> moves;
    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = { 1, -1,  2, -2, 2,-2, 1,-1};

    if(x >= 0 && x < 8 && y >= 0 && y < 8) {
        for(int i = 0; i < 8; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(canMove(x, y, newX, newY, board)) {
                moves.push_back({newX, newY});
            }
        }
    }
    return moves;
}