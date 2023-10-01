// figure.h

#ifndef FIGURE_H
#define FIGURE_H
#include <vector>
#include <math.h>
#include <Color.h>
using namespace std;

class Figure {
public:
    Figure(char name);
    char getName();
    Color getColor();
    virtual bool canMove(int currentX, int currentY, int newX, int newY, Figure* board[8][8]) = 0; 
    virtual vector<pair<int, int>> generateMoves(int x, int y, Figure* board[8][8]) = 0;

protected:
    char name;
    Color color;
};

#endif