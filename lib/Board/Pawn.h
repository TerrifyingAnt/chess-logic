// класс пешки

#ifndef PAWN_H
#define PAWN_H

#include <Board.h>

class Pawn : public Figure {
public:
    Pawn(Color color);
    bool canMove(int currentX, int currentY, int newX, int newY, Figure* board[8][8]) override;
    vector<pair<int, int>> generateMoves(int x, int y, Figure* board[8][8]) override;
    bool checkForFirstMove(int x, int y);
}; 

#endif // PAWN_H
