#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

#include "dependencias.h"

int main(int argc, char** argv)
{
    if (argc > 1) {
        
        std::string linea;
        std::string ruta = argv[1];

        std::ifstream lectura;

        lectura.open(ruta, std::ios_base::in);

        if (lectura && std::string(ruta.substr(ruta.length()-9, 9)) == "datos.csv") {
            
            int muestra = 0;
            
            std::vector<ingresoDiario> ingresos = obtenerIngresos(lectura, muestra);

            lectura.close();

            if (ingresos.size() > 0) {
                
                /*
                * Sets de datos para trabajar.
                */
                std::vector<long long int> dias;
                std::vector<long long int> montos;
                double x[199];
                double y[199];
                int i=0;
                for (std::vector<ingresoDiario>::iterator it = ingresos.begin(); it != ingresos.end(); ++it,i++) {
                    dias.push_back(it -> dias);
                    montos.push_back(it -> monto);
                    x[i] = it -> dias;
                    y[i] = it -> monto;
                }

                std::srand(time(NULL));
                int evaluacion = std::rand() % (muestra - 1);

                std::cout << std::endl;

                std::cout << "\033[1;32m====================[Modelo #1 de Regresión Lineal de Mínimos Cuadrados Ordinarios]====================\033[0m" << std::endl;

                std::cout << std::endl;
                
                MCO modelo1(muestra, dias, montos, "fecha");

                std::cout << "Expresión : " << modelo1.getExpresion() << ", R² = " << modelo1.getR() << std::endl;

                std::cout << std::endl;

                modelo1.setExpresion("[" + ingresos.at(evaluacion).fecha + "]");

                std::cout << "Evaluando en la fecha " << ingresos.at(evaluacion).fecha << " (ingreso real del día : $" << ingresos.at(evaluacion).monto << ") : " << std::endl;
                
                std::cout << std::endl;
                
                std::cout << modelo1.getExpresion() << " = $" << modelo1.evaluar(ingresos.at(evaluacion).dias) << " CLP" << std::endl;

                std::cout << std::endl;

                std::cout << "\033[1;32m========================================================================================================\033[0m" << std::endl;
            



                int evaluacion2 = std::rand() % (muestra - 1);

                std::cout << "\033[1;32m====================[Modelo #2 de Regresión Polinomica]====================\033[0m" << std::endl;

                std::cout << std::endl;
                
                std::cout << "Evaluando en la fecha " << ingresos.at(evaluacion2).fecha << " (ingreso real del día : $" << ingresos.at(evaluacion2).monto << ") : " << std::endl;
                
                std::cout << std::endl;
                regresionPolinomica(x, y, sizeof(x)/sizeof(x[0]), 6, evaluacion2);
                std::cout <<" = $" << modelo1.evaluar(ingresos.at(evaluacion2).dias) << " CLP" << std::endl;

                std::cout << std::endl;

                std::cout << "\033[1;32m========================================================================================================\033[0m" << std::endl;
            
                
            }



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