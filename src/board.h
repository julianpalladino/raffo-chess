#pragma once

#include <vector>
#include <iostream>
#include <list>
#include "piece.h"

// #include "Tiempo.h"

using namespace std;

enum startingPosition { empty, standard };

class board {
  public:

    board();

    board(startingPosition pos);

    void movePiece(string move);

    void setPiece(string pos, piece p);

    void setPiece(int mX, int mY, piece p);

  protected:

    virtual void show() {}

    bool validateMove(string move);

    void changeTurn();

    bool validateVertical(int x, int fromY, int toY, color c);

    bool validateHorizontal(int y, int fromX, int toX, color c);

    bool validateDiagonal(int fromX,int fromY,int toX,int toY, color c);

    vector< vector<piece> > m;

    color turn;
};
