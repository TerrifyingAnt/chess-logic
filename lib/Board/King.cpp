
// king.cpp
#include <King.h>

King::King(Color color) : Figure('K') {
    this->color = color;
} 

bool King::canMove(int currentX, int currentY, int newX, int newY, Figure* board[8][8]) {

    int dx = abs(currentX - newX);
    int dy = abs(currentY - newY);

    return (dx <= MAX_DISTANCE) && (dy <= MAX_DISTANCE); 
}



vector<pair<int, int>> King::generateMoves(int x, int y, Figure* board[8][8]) {
    vector<pair<int, int>> moves;

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (canMove(x, y, newX, newY, board)) {
            moves.push_back({newX, newY});
        }
    }

    return moves;
}

bool King::ifCheckNextMove(int tempX, int tempY, int newX, int newY, Board* board) {
    // необходимо поставить фигуру на новое место и проверить, что король не под шахом
    // если король под шахом, то вернуть false, иначе true
    board->setPiece(nullptr, tempX, tempY);
    board->setPiece(this, newX, newY);
    bool result = board->isAttacked(newX, newY, this->getColor());
    board->setPiece(nullptr, newX, newY);
    board->setPiece(this, tempX, tempY);
    return result;
}

bool King::isSmallCastleAvailable(Board* board) {
    // проверить, что король и ладья не двигались
    // проверить, что между королем и ладьей нет фигур
    // проверить, что король не под шахом
    // проверить, что король не проходит через клетку под шахом
    // проверить, что король не проходит через клетку, на которой он под шахом
    if(this->getColor() == Color::WHITE) {
        if ((board->getPiece(7, 7) == nullptr || board->getPiece(7, 4) == nullptr) ||
            (board->getPiece(7, 7)->getName() != 'R' || board->getPiece(7, 4)->getName() != 'K') ||
            (board->getPiece(7, 7)->getColor() != Color::WHITE || board->getPiece(7, 4)->getColor() != Color::WHITE) || 
            (board->getPiece(7, 6) != nullptr) || (board->getPiece(7, 5) != nullptr)) {
            return false;
        }
        else {
            for(int i = 5; i < 7; i++) {
                if(this->ifCheckNextMove(7, i - 1, 7, i, board)) {
                    return false;
                }
            }
        }
        return true;
    }
    else {
        if ((board->getPiece(0, 7) == nullptr || board->getPiece(0, 4) == nullptr) ||
            (board->getPiece(0, 7)->getName() != 'R' || board->getPiece(0, 4)->getName() != 'K') ||
            (board->getPiece(0, 7)->getColor() != Color::BLACK || board->getPiece(0, 4)->getColor() != Color::BLACK) || 
            (board->getPiece(0, 6) != nullptr) || (board->getPiece(0, 5) != nullptr)) {
            return false;
        }
        else {
            for(int i = 5; i < 7; i++) {
                if(this->ifCheckNextMove(0, i - 1, 0, i, board)) {
                    return false;
                }
            }
        }
        return true;
    }

}

bool King::isBigCastleAvailable(Board* board) {
    // проверить, что король и ладья не двигались
    // проверить, что между королем и ладьей нет фигур
    // проверить, что король не под шахом
    // проверить, что король не проходит через клетку под шахом
    // проверить, что король не проходит через клетку, на которой он под шахом
    if(this->getColor() == Color::WHITE) {
        if ((board->getPiece(7, 0) == nullptr || board->getPiece(7, 4) == nullptr) ||
            (board->getPiece(7, 0)->getName() != 'R' || board->getPiece(7, 4)->getName() != 'K') ||
            (board->getPiece(7, 0)->getColor() != Color::WHITE || board->getPiece(7, 4)->getColor() != Color::WHITE) || 
            (board->getPiece(7, 1) != nullptr) || (board->getPiece(7, 2) != nullptr) || (board->getPiece(7, 3) != nullptr)) {
            return false;
        }
        else {
            for(int i = 3; i < 5; i++) {
                if(this->ifCheckNextMove(7, i - 1, 7, i, board)) {
                    return false;
                }
            }
        }
        return true;
    }
    else {
        if ((board->getPiece(0, 0) == nullptr || board->getPiece(0, 4) == nullptr) ||
            (board->getPiece(0, 0)->getName() != 'R' || board->getPiece(0, 4)->getName() != 'K') ||
            (board->getPiece(0, 0)->getColor() != Color::BLACK || board->getPiece(0, 4)->getColor() != Color::BLACK) || 
            (board->getPiece(0, 1) != nullptr) || (board->getPiece(0, 2) != nullptr) || (board->getPiece(0, 3) != nullptr)) {
            return false;
        }
        else {
            for(int i = 3; i < 5; i++) {
                if(this->ifCheckNextMove(0, i - 1, 0, i, board)) {
                    return false;
                }
            }
        }
        return true;
    }
}