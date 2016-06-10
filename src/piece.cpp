#include "piece.h"
#include <vector>
#include <iostream>

using namespace std;

piece::piece(void) {
  nil = true;
}


char piece::toChar(){
  // whites are in CAPS, blacks are not
  if(c == white){
    switch(k){
      case king:
        return 'K';
      case queen:
        return 'Q';
      case rook:
        return 'R';
      case bishop:
        return 'B';
      case knight:
        return 'N';
      case pawn:
        return 'P';
    }
  }else{
    switch(k){
      case king:
        return 'k';
      case queen:
        return 'q';
      case rook:
        return 'r';
      case bishop:
        return 'b';
      case knight:
        return 'n';
      case pawn:
        return 'p';
    }
  }
}

piece::piece(color colorInput, kind kindInput) {
  nil = false;
  c = colorInput;
  k = kindInput;
}