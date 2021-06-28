#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "ingresoDiario.h"

std::vector<ingresoDiario> obtenerIngresos(std::istream& lectura, int& dias)
{
    std::string linea;
    std::vector<ingresoDiario> ingresos;
    std::string fecha("0/0/0");
    int cantidadDiaria = 0;
    long long int montoDiario = 0;
    bool primeraLinea = true;

    while (std::getline(lectura, linea, '\n')) {
        
        std::stringstream ss(linea);
        std::string item;
        int columna = 0;
        std::string dia;
        int cantidad;
        long int monto;

        if (!primeraLinea) {
            
            while (std::getline(ss, item, ';')) {
                
                item = item.substr(1, item.length() - 2);
                
                if (columna == 0) {
                    dia = item.substr(0, 10);
                }

                if (columna == 2) {
                    cantidad = std::stoi(item);
                }

                if (columna == 3) {
                    monto = std::stoll(item);
                }
                
                ++columna;
            }

            if (fecha != dia && fecha != "0/0/0") {
                ingresos.push_back({ fecha, cantidadDiaria, montoDiario });
                cantidadDiaria = 0;
                montoDiario = 0;
                ++dias;
            }
            
            fecha = dia;
            cantidadDiaria += cantidad;
            montoDiario += (cantidad * monto);
        }

        primeraLinea = false;
    }

    if (lectura.eof()) {
        ingresos.push_back({ fecha, cantidadDiaria, montoDiario });
        ++dias;
    }

    return ingresos;
}