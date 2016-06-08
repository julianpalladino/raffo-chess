#include "board.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
  return 0;
}

board::board() {
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      m[i][j] = NULL;
    }
  }
}

void board::movePiece(string move){
  // For now, only interpreting the move in the way "AXBY",
  // where AX is the starting position of the piece and BY is the final

  if (m[move[0]-97][move[1]-48].c == turn){
    m[move[2]-97][move[3]-48] = m[move[0]-97][move[1]-48];
  }else{
    cout << "Not your turn" << endl;
  }
}
    
void board::setPiece(string pos, piece p){
  // For now, only interpreting the move in the way "AX",
  // where AX is the position
  m[pos[0]-97][pos[1]-48] = p;
}
