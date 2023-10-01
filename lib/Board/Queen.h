#ifndef QUEEN_H
#define QUEEN_H

#include <Board.h>

class Queen : public Figure {
public:
    Queen(Color color);
    bool canMove(int currentX, int currentY, int newX, int newY, Figure* board[8][8]) override;
    vector<pair<int, int>> generateMoves(int x, int y, Figure* board[8][8]) override;

};

#endif