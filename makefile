MKDIR=mkdir
CP=cp


taller02: dir main.o participantes.o
	g++ build/main.o build/participantes.o -o bin/taller02
	rm -fr build/*.o build

dir:
	mkdir -p build bin

main.o: main.cpp
	g++ -c main.cpp -o build/main.o

participantes.o: dependencias/participantes.cpp dependencias.h
	g++ -c dependencias/participantes.cpp -o build/participantes.o

clean:
	rm -fr build/*.o bin/* build bin