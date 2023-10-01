#include <Pawn.h>

Pawn::Pawn(Color color) : Figure('P') {
    this->color = color;
}

bool Pawn::canMove(int currentX, int currentY, int newX, int newY, Figure* board[8][8]) {
    // нужно проверить, может ли пешка идти вперед
    // нужно проверить, может ли пешка бить по диагонали
    // нужнро проверить, пустая ли впереди клетка
    return (currentX == newX) || (currentY == newY) &&  
        (newX >= 0) && (newX < 8) && (newY >= 0) && (newY < 8) && board[newX][newY] == nullptr;
}

vector<pair<int, int>> Pawn::generateMoves(int x, int y, Figure* board[8][8]) {
    // ходы, которые может совершить пешка
    // если пешка белая, то она может идти вверх
    // если пешка черная, то она может идти вниз
    // если есть фигуры по диагонали - можно пойти туда и съесть фигуру
    vector<pair<int, int>> moves;
    if(this->getColor() == Color::WHITE) {
        moves.push_back({x, y + 1});
        if (checkForFirstMove(x, y)) {
            moves.push_back({x, y + 2});
        }
        if(x + 1 < 8 && board[x + 1][y + 1] != nullptr && board[x + 1][y + 1]->getColor() != this->getColor()) {
            moves.push_back({x + 1, y + 1});
        }
        if(x - 1 >= 0 && board[x - 1][y + 1] != nullptr && board[x - 1][y + 1]->getColor() != this->getColor()) {
            moves.push_back({x - 1, y + 1});
        }
    }
    else {
        moves.push_back({x, y - 1});
        if (checkForFirstMove(x, y)) { 
            moves.push_back({x, y - 2});
        }
        if(x + 1 < 8 && board[x + 1][y - 1] != nullptr && board[x + 1][y - 1]->getColor() != this->getColor()) {
            moves.push_back({x + 1, y - 1});
        }
        if(x - 1 >= 0 && board[x - 1][y - 1] != nullptr && board[x - 1][y - 1]->getColor() != this->getColor()) {
            moves.push_back({x - 1, y - 1});
        }
    }
    return moves;
}

bool Pawn::checkForFirstMove(int x, int y) {
    // проверка на первый ход пешки (может сходить на 2 клетки) 
    if (this->getColor() == Color::WHITE) {
        if (y == 1) {
            return true;
        }
    }
    else {
        if (y == 6) {
            return true;
        }
    }
    return false;
}

