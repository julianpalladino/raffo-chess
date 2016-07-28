CPPFLAGS= -g -std=c++11
OBJS= boardConsole.o boardDisplay.o board.o piece.o

main: main.cpp $(OBJS)
	g++ $(CPPFLAGS) main.cpp $(OBJS) -o main `pkg-config --libs allegro-5 allegro_image-5 allegro_font-5 allegro_color-5 allegro_ttf-5 allegro_primitives-5`

boardConsole.o: boardConsole.h boardConsole.cpp board.o
	g++ -c $(CPPFLAGS) board.o boardConsole.cpp -o boardConsole.o

boardDisplay.o: boardDisplay.cpp boardDisplay.h
	g++ -c $(CPPFLAGS) board.o boardDisplay.cpp -o boardDisplay.o `pkg-config --libs allegro-5 allegro_image-5 allegro_font-5 allegro_color-5 allegro_ttf-5 allegro_primitives-5`

board.o: board.cpp board.h piece.o
	g++ -c $(CPPFLAGS) piece.o board.cpp -o board.o

piece.o: piece.cpp piece.h
	g++ -c $(CPPFLAGS) piece.cpp -o piece.o

clean:
	rm *.o main
