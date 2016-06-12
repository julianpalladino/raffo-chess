#include "board.h"
#include <vector>
#include <iostream>
#include <string> 

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
  for(int i = 7; i >= 0; i--){
    for(int j = 0; j < 8; j++){
      if (m[i][j].nil){
        cout << " · ";
      }else{
        cout << " " << m[i][j].toChar() << " ";
      }
    }
    cout << "   " << i+1 << endl;
  }

  // letters
  cout << endl;
  for(int i = 0; i < 8; i++){

    char a = i+97;
    cout << " " << a << " ";
  }
  cout << endl;
}

void board::movePiece(string move){
  // For now, only interpreting the move in the way "AXBY",
  // where AX is the starting position of the piece and BY is the final

  if (!m[move[1]-49][move[0]-97].nil && m[move[1]-49][move[0]-97].c == turn){
    m[move[3]-49][move[2]-97] = m[move[1]-49][move[0]-97];
    m[move[1]-49][move[0]-97].nil = true;
  }else{
    cout << "Invalid move" << endl;
  }
}

bool validateVertical(int fromY, int toY, color c){
  return true;
}

bool validateHorizontal(int fromX, int toX, color c){
  return true;
}

bool validateDiagonal(int fromX,int fromY,int toX,int toY, color c){
  return true;
}


bool board::validateMove(string move){
  int fromX = move[1]-49;
  int fromY = move[0]-97;
  int toX = move[3]-49;
  int toY = move[2]-97;
  bool valid = true;

  switch(m[fromX][fromY].k){
    case king:
      // TODO: validate check
      return (toX - fromX <= 1 && toY-fromY <= 1);

    case queen:
      if(fromX == toX){
        return validateVertical(fromY, toY, m[fromX][fromY].c);
      }else if(fromY == toY){
        return validateHorizontal(fromX, toX, m[fromX][fromY].c);
      }else if(toY-fromY == toX-fromX){
        return validateDiagonal(fromX, fromY, toX, toY, m[fromX][fromY].c);
      }else{
        return false;
      }
    case rook:
      if(fromX == toX){
        return validateVertical(fromY, toY, m[fromX][fromY].c);
      }else if(fromY == toY){
        return validateHorizontal(fromX, toX, m[fromX][fromY].c);
      }else{
        return false;
      }
    case bishop:
      if(toY-fromY == toX-fromX){
        return validateDiagonal(fromX, fromY, toX, toY, m[fromX][fromY].c);
      }else{
        return false;
      }
    case knight:
      //todo
    case pawn:
      //todo
    break;
  }
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
