CC=g++
test: test.cpp GameIcon.o
	$(CC) -lGL -lglut test.cpp pugixml.o GameIcon.o -o test
GameIcon.o: GameIcon.cpp
	$(CC) -c GameIcon.cpp
clean:
	rm test
