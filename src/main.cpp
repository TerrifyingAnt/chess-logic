#include <Arduino.h>
#include <Board.h>
#include <King.h>
#include <Rook.h>
#include <Pawn.h>
#include <Knight.h>
#include <Bishop.h>
#include <Queen.h>

void setup() {
  Board* field = new Board();
  King* king = new King(Color::WHITE);
  Rook* rook = new Rook(Color::WHITE);
  Pawn* pawn = new Pawn(Color::WHITE);
  Knight* knight = new Knight(Color::WHITE);
  Bishop* bishop = new Bishop(Color::WHITE);
  Queen* queen = new Queen(Color::WHITE);
}

void loop() {
  // put your main code here, to run repeatedly:

}

