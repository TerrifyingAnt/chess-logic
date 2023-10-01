// board.h 

#ifndef BOARD_H
#define BOARD_H

#include "Figure.h"

class Board {
public:
    Board();
    Figure* getPiece(int x, int y);
    void setPiece(Figure* piece, int x, int y);
    bool isAttacked(int x, int y, Color color);

private:
    Figure* board[8][8]; 
};

#endif