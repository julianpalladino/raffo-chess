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
    vector< vector<piece> > m;
    color turn;
    board();
    board(startingPosition pos);

    void show();

    void movePiece(string move);
    
    bool validateMove(string move);

    void setPiece(string pos, piece p);

    void setPiece(int mX, int mY, piece p);
};
