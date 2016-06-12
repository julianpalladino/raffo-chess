#include <iostream>
#include <vector>
#include "boardDisplay.h"
#include "boardConsole.h"

using namespace std;

void printIndented(const string &s, int indentations){
  for (int i = 0; i < indentations; ++i){
    cout << "    ";
  }
  cout << s << endl;
}

void printHelpMenu() {
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
}

using namespace std;

int main(int argc, char const *argv[]) {
  boardDisplay b;
  string move;
  string enterAndIndent = "\n    ";
  string indent = "    ";
  cout << "Insert command (h for help):  ";
  cin >> move;
  while (move != "q"){
    if (move == "h"){
      printHelpMenu();
    } else {
      if (move.size() == 7 && move.substr(0,3) == "set"){
        b.setPiece(move.substr(3,2), piece(move.substr(5,2)));
      } else {
        b.movePiece(move);
      }
    }
    cout << endl << endl << endl;
    cout << "Insert command (h for help):  ";
    cin >> move;
  }
  return 0;
}
