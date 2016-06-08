#include <iostream>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

int main(int argc, char const *argv[])
{
  if (!al_init()) cerr << "Error inicializando allegro\n";
  if (!al_init_image_addon()) cerr << "Error inicializando imagenes\n";
  al_set_new_display_option(ALLEGRO_SINGLE_BUFFER, 1, ALLEGRO_SUGGEST);
  al_set_new_display_flags(ALLEGRO_WINDOWED);
  if (!al_init_primitives_addon()) cerr << "Error iniciando primitivas\n";
  ALLEGRO_DISPLAY * display = al_create_display(440, 440);
  ALLEGRO_BITMAP * backbuffer = al_get_backbuffer(display);
  al_clear_to_color(al_map_rgb(150,150,150));



  char a;
  cin >> a;
  al_destroy_display(display);
  return 0;
}
