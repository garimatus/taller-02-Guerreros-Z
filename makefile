MKDIR=mkdir
CP=cp


taller02: dir main.o participantes.o obtenerIngresos.o regresionPolinomica.o mco.o
	g++ build/main.o build/participantes.o build/obtenerIngresos.o build/regresionPolinomica.o build/mco.o -o bin/taller02
	rm -fr build/*.o build

dir:
	mkdir -p build bin

main.o: main.cpp
	g++ -c main.cpp -o build/main.o

participantes.o: dependencias/participantes.cpp dependencias.h
	g++ -c dependencias/participantes.cpp -o build/participantes.o

obtenerIngresos.o: dependencias/obtenerIngresos.cpp dependencias/RataDie.cpp dependencias.h
	g++ -c dependencias/obtenerIngresos.cpp -o build/obtenerIngresos.o

regresionPolinomica.o: dependencias/regresionPolinomica.cpp dependencias.h
	g++ -c dependencias/regresionPolinomica.cpp -o build/regresionPolinomica.o

mco.o: dependencias/MCO.cpp dependencias.h
	g++ -c dependencias/MCO.cpp -o build/mco.o

clean:
	rm -fr build/*.o bin/* build bin