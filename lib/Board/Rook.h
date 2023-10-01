// класс ладьи

#ifndef ROOK_H
#define ROOK_H

#include <Board.h>

class Rook : public Figure {
public:
    Rook(Color color);
    bool canMove(int currentX, int currentY, int newX, int newY, Figure* board[8][8]) override;
    vector<pair<int, int>> generateMoves(int x, int y, Figure* board[8][8]) override;

};


#endif