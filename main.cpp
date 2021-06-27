#include <iostream>
#include <fstream>
#include <vector>

#include "dependencias.h"

int main(int argc, char** argv)
{
    if (argc > 1) {
        
        std::string linea;
        std::string ruta = argv[1];

        std::ifstream lectura;

        lectura.open(ruta, std::ios_base::in);

        if (lectura && std::string(ruta.substr(ruta.length()-9, 9)) == "datos.csv") {
            
            int dias = 0;
            
            std::vector<ingresoDiario> ingresos = obtenerIngresos(lectura, dias);

            lectura.close();
            
            participantes("32");
            
            return EXIT_SUCCESS;
            
        } else {
            
            std::cout << "\033[1;31mEl nombre del archivo solicitado es incorrecto o este no existe en el directorio local.\033[0m" << std::endl;

            participantes("31");

            return EXIT_FAILURE;
        }

    } else {
        
        std::cout << "\033[1;31mNo se ha ingresado la ruta del archivo solicitado.\033[0m" << std::endl;
        
        participantes("31");

        return EXIT_FAILURE;
    }
}