CPPFLAGS= -g -std=c++11
OBJS=display.o

main: main.cpp $(OBJS)
	g++ $(CPPFLAGS) main.cpp $(OBJS) -o main `pkg-config --libs allegro-5.0 allegro_image-5.0 allegro_font-5.0 allegro_color-5.0 allegro_ttf-5.0 allegro_primitives-5.0`


display.o: display.cpp display.h
	g++ -c $(CPPFLAGS) display.cpp -o display.o `pkg-config --libs allegro-5.0 allegro_image-5.0 allegro_font-5.0 allegro_color-5.0 allegro_ttf-5.0 allegro_primitives-5.0`

board.o: board.cpp board.h piece.o
	g++ -c $(CPPFLAGS) board.cpp piece.o -o board.o

piece.o: piece.cpp piece.h
	g++ -c $(CPPFLAGS) piece.cpp -o piece.o

clean:
	rm *.o main
