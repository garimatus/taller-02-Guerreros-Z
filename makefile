MKDIR=mkdir
CP=cp


taller02: dir main.o participantes.o obtenerIngresos.o regresionLineal.o
	g++ build/main.o build/participantes.o build/obtenerIngresos.o build/regresionLineal.o -o bin/taller02
	rm -fr build/*.o build

dir:
	mkdir -p build bin

main.o: main.cpp
	g++ -c main.cpp -o build/main.o

participantes.o: dependencias/participantes.cpp dependencias.h
	g++ -c dependencias/participantes.cpp -o build/participantes.o

obtenerIngresos.o: dependencias/obtenerIngresos.cpp dependencias/RataDie.cpp dependencias.h
	g++ -c dependencias/obtenerIngresos.cpp -o build/obtenerIngresos.o

regresionLineal.o: dependencias/regresionLineal.cpp dependencias.h
	g++ -c dependencias/regresionLineal.cpp -o build/regresionLineal.o

clean:
	rm -fr build/*.o bin/* build bin