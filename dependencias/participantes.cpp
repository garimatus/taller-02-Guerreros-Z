#include <iostream>

#include "../dependencias.h"


void participantes(const char* color)
{
    std::cout << "\033[1;"+std::string(color)+"m\n=== Integrantes ===\n\nEdgar I. Matus Soto\n\nAlex Bidart\n\nNicolás Jiménez\n\033[0m" << std::endl;
}