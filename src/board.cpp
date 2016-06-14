#include "board.h"
#include <vector>
#include <iostream>
#include <string> 
#include <sstream>
using namespace std;


using namespace std;

void raffoChess(){
  cout << "_________________________________________________________________________________________________________________________________________________" << endl << endl;
  cout << "      ,...., " << endl;
  cout << "    ,::::::< " << endl;
  cout << "   ,::/^\"``. " << endl;
  cout << "  ,::/, `   e`.          ██████╗  █████╗ ███████╗███████╗ ██████╗      ██████╗██╗  ██╗███████╗███████╗███████╗ " << endl;
  cout << " ,::; |        '.        ██╔══██╗██╔══██╗██╔════╝██╔════╝██╔═══██╗    ██╔════╝██║  ██║██╔════╝██╔════╝██╔════╝ " << endl;
  cout << " ,::|  \\___,-.  c)       ██████╔╝███████║█████╗  █████╗  ██║   ██║    ██║     ███████║█████╗  ███████╗███████╗ " << endl;
  cout << " ;::|     \\   '-'        ██╔══██╗██╔══██║██╔══╝  ██╔══╝  ██║   ██║    ██║     ██╔══██║██╔══╝  ╚════██║╚════██║ " << endl;
  cout << " ;::|      \\             ██║  ██║██║  ██║██║     ██║     ╚██████╔╝    ╚██████╗██║  ██║███████╗███████║███████║ " << endl;
  cout << " ;::|   _.=`\\            ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝      ╚═════╝      ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝ " << endl;
  cout << " `;:|.=` _.=`\\ " << endl;
  cout << "   '|_.=`   __\\" << endl;
  cout << "   `\\_..==`` / " << endl;
  cout << "    .'.___.-'. " << endl;
  cout << "   /          \\ " << endl;
  cout << "  ('--......--') " << endl;
  cout << "  /'--......--'\\ " << endl;
  cout << "  `'--......--'` " << endl;
  cout << "_________________________________________________________________________________________________________________________________________________" << endl << endl;
}

void printIndented(const string &s, int indentations){
  for(int i = 0; i < indentations; ++i){
    cout << "    ";
  }
  cout << s << endl;
}

int main() {
  board b(standard);
  string move;
  string enterAndIndent = "\n    ";
  string indent = "    ";
  raffoChess();
  while(move != "q"){
    b.show();
    cout << "Insert command (h for help):  ";
    cin >> move;
    if (move == "h"){            
      cout << "______________________________________________Help menu______________________________________________" << endl;
      printIndented("Commands",0);
      printIndented("Help: h",1);
      printIndented("Quit: q",1);
      printIndented("Move piece:",1);
      printIndented("'AXBY' where AX is the starting position of the piece and BY is the final",2);
      printIndented("Set piece:",1);
      printIndented("'setAXCK' where AX is the position, K is the kind (K, Q, R, N, B, P), C is the color (B, W)",2);
      cout << endl << endl;
      printIndented("Game notations",0);
      printIndented("King: K",1);
      printIndented("Queen: Q",1);
      printIndented("Rook: R",1);
      printIndented("Bishop: B",1);
      printIndented("Knight: N",1);
      printIndented("Pawn: P",1);
      cout << "_____________________________________________________________________________________________________" << endl;
    }else{
      if(move.size() == 7 && move.substr(0,3) == "set"){
        b.setPiece(move.substr(3,2), piece(move.substr(5,2)));
      }else{
        b.movePiece(move);
      }
    }

    cout << endl << endl << endl;
  }


  return 0;
}



board::board() {}

board::board(startingPosition pos) {
  turn = white;
  m = vector<vector<piece> > (8, vector<piece>(8));
  if(pos == standard){
    // white pawns
    for(int i = 0; i < 8; i++){
      setPiece(1,i,piece(white, pawn));
    }

    // white other pieces
    setPiece("a1", piece(white, rook));
    setPiece("b1", piece(white, knight));
    setPiece("c1", piece(white, bishop));
    setPiece("d1", piece(white, queen));
    setPiece("e1", piece(white, king));
    setPiece("f1", piece(white, bishop));
    setPiece("g1", piece(white, knight));
    setPiece("h1", piece(white, rook));


    // black pawns
    for(int i = 0; i < 8; i++){  
      setPiece(6,i,piece(black, pawn));
    }

    // black other pieces
    setPiece("a8", piece(black, rook));
    setPiece("b8", piece(black, knight));
    setPiece("c8", piece(black, bishop));
    setPiece("d8", piece(black, queen));
    setPiece("e8", piece(black, king));
    setPiece("f8", piece(black, bishop));
    setPiece("g8", piece(black, knight));
    setPiece("h8", piece(black, rook));
  }
}

void board::show(){
  bool color = true;
  for(int i = 7; i >= 0; i--){
    for(int j = 0; j < 8; j++){
      if (color){
        cout << "\033[44m";
      }else{
        cout << "\033[46m";
      }

      if (m[i][j].nil){
        cout << "  ";
      }else{
        cout << m[i][j].toCharPiece() << " ";
      }

      color = !color;
    }
    color = !color;
    cout << "\033[0m" << i+1 << endl;
  }

  // letters
  for(int i = 0; i < 8; i++){

    char a = i+65;
    cout << a << " ";
  }
  cout << endl;
}

void board::movePiece(string move){
  // For now, only interpreting the move in the way "AXBY",
  // where AX is the starting position of the piece and BY is the final

  if (!m[move[1]-49][move[0]-97].nil && m[move[1]-49][move[0]-97].c == turn && validateMove(move)){
    m[move[3]-49][move[2]-97] = m[move[1]-49][move[0]-97];
    m[move[1]-49][move[0]-97].nil = true;
    changeTurn();
  }else{
    cout << "Invalid move" << endl;
  }
}

void board::changeTurn(){
  if (turn == white){
    turn = black;
  }else{
    turn = white;
  }
}

bool board::validateVertical(int x, int fromY, int toY, color c){
  int lower = min(fromY, toY);
  int higher = max(fromY, toY);
  for(int i = lower; i < higher-1; ++i){
    if (!m[x][i].nil && i != fromY){
      return false;
    }
  }
  return true;
}

bool board::validateHorizontal(int y, int fromX, int toX, color c){
  int lower = min(fromX, toX);
  int higher = max(fromX, toX);
  for(int i = lower; i < higher-1; ++i){
    if (!m[i][y].nil && i != fromX){
      cout << i << ", " << y << m[i][y].toCharPiece() << endl;
      return false;
    }
  }
  return true;
}

bool board::validateDiagonal(int fromX,int fromY,int toX,int toY, color c){
  int j;
  if(toY - fromY == toX - fromX){ // going in the same direction
    for(int i = min(fromX, toX), j = min(fromY, toY); i < max(fromX, toX)-1; ++i, ++j){
      if (!m[i][j].nil && i != fromX && j != fromY){
        return false;
      }
    }
  }else{
    for(int i = min(fromX, toX), j = max(fromY, toY); i < max(fromX, toX)-1; ++i, --j){
      if (!m[i][j].nil){
        return false;
      }
    }
  }
  return true;
}

int abs(int n){
  if (n<0){
    return n*(-1);
  }
  return n;
}

bool board::validateMove(string move){
  int fromX = move[1]-49;
  int fromY = move[0]-97;
  int toX = move[3]-49;
  int toY = move[2]-97;
  bool valid = true;
  // Validates board limits
  if (toX % 8 != toX || toY % 8 != toY){
    return false;
  }

  // Validates color turn
  if (m[fromX][fromY].c != turn){
    return false;
  }

  // Validates not eating self color piece
  if (!m[toX][toY].nil && (m[toX][toY].c == m[fromX][fromY].c)){
    return false;
  }
  if (m[fromX][fromY].k == king){
    // TODO: validate check
    // TODO: validate castle
    return (toX - fromX <= 1 && toY-fromY <= 1);
  }
  if (m[fromX][fromY].k == knight){
    return (abs(fromY - toY) * abs(fromX - toX) == 2);
  }
  if (m[fromX][fromY].k == pawn){
    //todo
    if (m[fromX][fromY].c == white && (fromX==1 && toX == 3) || toX==fromX+1){
      return true;
    }
    if (m[fromX][fromY].c == black && (fromX==6 && toX == 4) || toX==fromX-1){
      return true;
    }
  }
  if (fromX == toX && (m[fromX][fromY].k == queen || m[fromX][fromY].k == rook)){
    return validateVertical(fromX, fromY, toY, m[fromX][fromY].c);
  }
  if (fromY == toY && (m[fromX][fromY].k == queen || m[fromX][fromY].k == rook)){
    return validateHorizontal(fromY, fromX, toX, m[fromX][fromY].c);
  }
  if(abs(toY-fromY) == abs(toX-fromX) && (m[fromX][fromY].k == queen || m[fromX][fromY].k == bishop)){
    return validateDiagonal(fromX, fromY, toX, toY, m[fromX][fromY].c);
  }
  return false;
}
    
void board::setPiece(string pos, piece p){
  // For now, only interpreting the move in the way "AX",
  // where AX is the position
  m[pos[1]-49][pos[0]-97] = p;
}

// recieves the matrix position
void board::setPiece(int mX, int mY, piece p){
  m[mX][mY] = p;
}
