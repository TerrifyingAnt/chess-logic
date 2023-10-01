// king.h

#ifndef KING_H
#define KING_H

#include <Board.h>

class King : public Figure {
public:
    King(Color color);
    bool canMove(int currentX, int currentY, int newX, int newY, Figure* board[8][8]) override;
    vector<pair<int, int>> generateMoves(int x, int y, Figure* board[8][8]) override;
    bool ifCheckNextMove(int tempX, int tempY, int newX, int newY, Board* board);
    bool isSmallCastleAvailable(Board* board);
    bool isBigCastleAvailable(Board* board);


private:
    static const int MAX_DISTANCE = 1;
};

#endif