#ifndef BISHOP_H
#define BISHOP_H

#include <Board.h>

class Bishop : public Figure {
public:
    Bishop(Color color);
    bool canMove(int currentX, int currentY, int newX, int newY, Figure* board[8][8]) override;
    vector<pair<int, int>> generateMoves(int x, int y, Figure* board[8][8]) override;
};

#endif