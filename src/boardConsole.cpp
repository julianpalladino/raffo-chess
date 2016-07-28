#include "boardConsole.h"

using namespace std;


boardConsole::boardConsole(): board() {
  show();
}

void boardConsole::show(){
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
