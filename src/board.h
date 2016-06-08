#pragma once

#include <vector>
#include <iostream>
#include <list>
#include "piece.h"
// #include "Tiempo.h"

using namespace std;


class board {
  public:
    vector< vector<piece> > m;
    color turn;
    board();

    void movePiece(string move);

    void setPiece(string pos, piece p);
};