#include <iostream>
#include <fstream>
#include <vector>

#include "dependencias.h"

int main(int argc, char** argv)
{
    std::string linea;
    std::string ruta = argv[1];

    std::ifstream lectura;

    lectura.open(ruta, std::ios_base::in);

    if (lectura && std::string(ruta.substr(ruta.length()-9, 9)) == "datos.csv")
    {
        int dias = 0;

        const char* color = "32";
        
        std::vector<ingresoDiario> ingresos = obtenerIngresos(lectura, dias);

        participantes(color);
        
        lectura.close();
        
        return EXIT_SUCCESS;
        
    } else {
        
        std::cout << "El nombre del archivo solicitado es incorrecto o este no existe en el directorio local." << std::endl;

        const char* color = "31";

        participantes(color);

        return EXIT_FAILURE;
    }
}