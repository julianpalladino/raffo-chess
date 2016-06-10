#pragma once


#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>

class board {};

class display {
  public:
    display();
    ~display();
    void refresh();

  private:
    display(display &);
    board brd;
    ALLEGRO_DISPLAY * window;
    void clear_square(int i, int j);

    static const int square_size = 60;
    static const int margin_size = 20;
    ALLEGRO_COLOR square_color[2];
};
