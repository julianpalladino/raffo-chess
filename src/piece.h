#pragma once

#include <vector>
#include <iostream>
#include <list>
#include "piece.h"
// #include "Tiempo.h"

using namespace std;

enum color { white, black };

enum kind { king, queen, rook, bishop, knight, pawn };

class piece {    
  public:
    bool nil;
    color c;
    kind k;
    piece();
    piece(color c, kind k);
    char toChar();
};
