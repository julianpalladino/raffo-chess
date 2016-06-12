#include "piece.h"
#include <vector>
#include <iostream>

using namespace std;

piece::piece(void) {
  nil = true;
}

piece::piece(string notation) { //notation is CK, where C is color and K is kind
  nil = false;
  color inputC;
  kind inputK;
  switch(notation[0]){
    case 'w':
      inputC = white;
      break;
    case 'W':
      inputC = white;
      break;
    case 'b':
      inputC = black;
      break;
    case 'B':
      inputC = black;
      break;
    default:
      nil = true;
  }

  switch(notation[1]){
    case 'k':
      inputK = king;
      break;
    case 'q':
      inputK = queen;
      break;
    case 'r':
      inputK = rook;
      break;
    case 'b':
      inputK = bishop;
      break;
    case 'n':
      inputK = knight;
      break;
    case 'p':
      inputK = pawn;
      break;
    case 'K':
      inputK = king;
      break;
    case 'Q':
      inputK = queen;
      break;
    case 'R':
      inputK = rook;
      break;
    case 'B':
      inputK = bishop;
      break;
    case 'N':
      inputK = knight;
      break;
    case 'P':
      inputK = pawn;
      break;
    default:
      nil = true;
  }

  c = inputC;
  k = inputK;
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