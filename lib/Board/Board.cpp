#include "Board.h"

Board::Board() {
  // Инициализация массива указателей на фигуры
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = nullptr; 
        }
    }
    for (int i = 0; i < 8; i++) {
        board[1][i] = new Pawn(Color::WHITE);
        board[6][i] = new Pawn(Color::BLACK);
    }
    board[0][0] = new Rook(Color::WHITE);
    board[0][7] = new Rook(Color::WHITE);
    board[7][0] = new Rook(Color::BLACK);
    board[7][7] = new Rook(Color::BLACK);
    board[0][1] = new Knight(Color::WHITE);
    board[0][6] = new Knight(Color::WHITE);
    board[7][1] = new Knight(Color::BLACK);
    board[7][6] = new Knight(Color::BLACK);
    board[0][2] = new Bishop(Color::WHITE);
    board[0][5] = new Bishop(Color::WHITE);
    board[7][2] = new Bishop(Color::BLACK);
    board[7][5] = new Bishop(Color::BLACK);
    board[0][3] = new Queen(Color::WHITE);
    board[7][3] = new Queen(Color::BLACK);
    board[0][4] = new King(Color::WHITE);
    board[7][4] = new King(Color::BLACK);
}

Figure* Board::getPiece(int x, int y) {
    // Проверка корректности координат
    if (x < 0 || x >= 8 || y < 0 || y >= 8) {
        return nullptr;
    }
    return board[x][y];
}

void Board::setPiece(Figure* piece, int x, int y) {
    // Проверка корректности координат
    if (x < 0 || x >= 8 || y < 0 || y >= 8) {
        return;
    }
    board[x][y] = piece; 
}

bool Board::isAttacked(int x, int y, Color color) {
    // для всех фигур на доске цвета color проверить, может ли она попасть на клетку (x, y)
    // если да, то вернуть true, иначе false
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            Figure* figure = board[i][j];
            if (figure != nullptr && figure->getColor() == color) {
                if (figure->canMove(i, j, x, y, board)) {
                    return true;
                }
            }
        }
    }
    return false;
}



