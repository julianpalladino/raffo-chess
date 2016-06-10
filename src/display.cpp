#include <iostream>
#include "display.h"

using namespace std;

const char* numbers[] = {"1", "2", "3", "4", "5", "6", "7", "8"};
const char* letters[] = {"a", "b", "c", "d", "e", "f", "g", "h"};

display::display(/*board & b*/)/*: brd(b)*/ {
  if (!al_init()) cerr << "Error initializing allegro\n";
  if (!al_init_image_addon()) cerr << "Error initializing images\n";
  al_init_font_addon();
  if (!al_init_ttf_addon()) cerr << "Error initializing ttf\n";
  al_set_new_display_option(ALLEGRO_SINGLE_BUFFER, 1, ALLEGRO_SUGGEST);
  al_set_new_display_flags(ALLEGRO_FRAMELESS);
  if (!al_init_primitives_addon()) cerr << "Error initializing primitives\n";
  int board_size = 2 * margin_size + 8 * square_size;
  window = al_create_display(board_size, board_size);
  al_clear_to_color(al_map_rgb(150,150,150));

  square_color[0] = al_map_rgb(50, 50, 50);
  square_color[1] = al_map_rgb(200, 200, 200);

  ALLEGRO_FONT * font = al_load_ttf_font("../assets/fonts/Arial.ttf", 15, 0);
  if (!font) cerr << "ERROR loading font\n";
  for (int i=0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      clear_square(i, j);
    }
    int text_offset = margin_size + i * square_size + square_size / 2;
    al_draw_text(font, al_map_rgb(0,0,0), text_offset - 5, board_size - 18, 0, letters[i]);
    al_draw_text(font, al_map_rgb(0,0,0), text_offset - 5, 2, 0, letters[i]);
    al_draw_text(font, al_map_rgb(0,0,0), 5, board_size - text_offset - 5, 0, numbers[i]);
    al_draw_text(font, al_map_rgb(0,0,0), board_size - 15, board_size - text_offset - 5, 0, numbers[i]);
  }


  al_flip_display();
}

void display::clear_square(int i, int j) {
  al_draw_filled_rectangle(margin_size + square_size * (i),
                           square_size * (7 - j) + margin_size,
                           margin_size + square_size * (i + 1),
                           square_size * (8 - j) + margin_size,
                           square_color[(i + j) & 1]); // 0 = black, 1 = white
}

display::~display() {
  al_destroy_display(window);
}
