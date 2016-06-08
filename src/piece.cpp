#include "piece.h"
#include <vector>
#include <iostream>

using namespace std;

piece::piece(void) {

}

piece::piece(color colorInput, kind kindInput) {
  c = colorInput;
  k = kindInput;
}