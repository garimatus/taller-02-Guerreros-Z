#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "ingresoDiario.h"

std::vector<ingresoDiario> obtenerIngresos(std::istream& lectura, int& dias)
{
    std::string linea;
    std::vector<ingresoDiario> ingresos;
    std::string dia("0/0/0");
    long long int montoDiario;

    while (std::getline(lectura, linea, '\n'))
    {
        std::stringstream ss(linea);
        std::string item;
        int columna = 0;
        std::string fecha;
        int cantidad;
        long int monto;

        while (std::getline(ss, item, ';'))
        {
            if (columna == 0)
            {
                fecha = item.substr(1, 10);
            }

            if (columna == 2)
            {
                cantidad = stoi(item);
            }

            if (columna == 3)
            {
                monto = stoi(item);
            }
            
            ++columna;
        }
        
        if (fecha == dia)
        {
            montoDiario += cantidad * monto;

        } else {     
            
            ingresoDiario temp = { dia, montoDiario };
            ingresos.push_back(temp);
            montoDiario = 0;
            dia = fecha;
        }
    }

    return ingresos;
}