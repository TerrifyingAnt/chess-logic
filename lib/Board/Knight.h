#ifndef KNIGHT_H
#define KNIGHT_H

#include <Board.h>

class Knight : public Figure {
public:
    Knight(Color color);
    bool canMove(int currentX, int currentY, int newX, int newY, Figure* board[8][8]) override;
    vector<pair<int, int>> generateMoves(int x, int y, Figure* board[8][8]) override;
};

#endif