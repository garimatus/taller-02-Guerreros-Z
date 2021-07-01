#include "./dependencias/ingresoDiario.h"
#include "./dependencias/MCO.h"


#include <vector>


void participantes(const char*);

std::vector<ingresoDiario> obtenerIngresos(std::istream&, int&);

void eliminacionGauss(double **, double [], int );
void sustitucionAtras(double **, double [], int , double []);
long double  regresionPolinomica(double [], double [], int , int, int);

int rdn(int, int, int);

