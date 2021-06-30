#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "../dependencias.h"
#include "./RataDie.cpp"

std::vector<ingresoDiario> obtenerIngresos(std::istream& lectura, int& dias)
{
    std::string linea;
    std::vector<ingresoDiario> ingresos;
    std::string fecha("0-0-0");
    std::vector<std::string> fechaInicial;
    int cantidadDiaria = 0;
    long int difDias = 0;
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

                    if (fecha == "0-0-0") {
                        std::string temp;
                        std::stringstream ss(dia);
                        while (getline(ss, temp, '-')) { fechaInicial.push_back(temp); }
                    }
                }

                if (columna == 2) {
                    cantidad = std::stoi(item);
                }

                if (columna == 3) {
                    monto = std::stoll(item);
                }
                
                ++columna;
            }

            if (fecha != dia && fecha != "0-0-0") {
                std::vector<std::string> fechaActual;
                std::stringstream ss(fecha);
                std::string temp;
                while (std::getline(ss, temp, '-')) { fechaActual.push_back(temp); };
                difDias = rdn(std::stoi(fechaActual.at(0)), std::stoi(fechaActual.at(1)), std::stoi(fechaActual.at(2))) - rdn(std::stoi(fechaInicial.at(0)), std::stoi(fechaInicial.at(1)), std::stoi(fechaInicial.at(2)));
                ingresos.push_back({ fecha, cantidadDiaria, difDias, montoDiario });
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
        std::vector<std::string> fechaActual;
        std::stringstream ss(fecha);
        std::string temp;
        while (std::getline(ss, temp, '-')) { fechaActual.push_back(temp); };
        difDias = rdn(std::stoi(fechaActual.at(0)), std::stoi(fechaActual.at(1)), std::stoi(fechaActual.at(2))) - rdn(std::stoi(fechaInicial.at(0)), std::stoi(fechaInicial.at(1)), std::stoi(fechaInicial.at(2)));
        ingresos.push_back({ fecha, cantidadDiaria, difDias, montoDiario });
        ++dias;
    }

    return ingresos;
}