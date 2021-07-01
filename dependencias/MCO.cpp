#include <string>

#include "./MCO.h"


MCO::MCO(long int n, std::vector<long long int> datos_x, std::vector<long long int> datos_y, const char* variable)
{
    this -> X = datos_x;
    this -> Y = datos_y;
    this -> muestra = n;

    for (long int i = 0; i < n; ++i) {
        prom_x += X.at(i);
        prom_y += Y.at(i);
    }

    this -> prom_x /= n;
    this -> prom_y /= n;
    
    long double varianza_x = 0.0;
    long double varianza_y = 0.0;
    long double covarianza = 0.0;

    for (long int i = 0; i < n; ++i) {
        
        long double dif_xx = double(X.at(i) - prom_x);

        long double dif_yy = double(Y.at(i) - prom_y);

        varianza_y += (dif_yy * dif_yy);

        varianza_x += (dif_xx * dif_xx);

        covarianza += (X.at(i) * Y.at(i));
    }

    this -> pendiente = covarianza / varianza_x;

    this -> intercepto = prom_y - (pendiente * prom_x);

    this -> covarianza = ((covarianza / n) - (prom_x * prom_y));

    this -> varianza_x /= n;

    this -> varianza_y /= n;

    this -> R2 = (covarianza / (varianza_x * varianza_y));

    setExpresion(variable);
}

MCO::~MCO()
{

}

long double MCO::evaluar(long double x)
{
    return (x * this -> pendiente) + this -> intercepto;
}

void MCO::setExpresion(std::string variable)
{
    this -> x = variable;
    
    if (intercepto > 0.0) {
        this -> expresion = std::to_string(pendiente) + "×" + x + " +" + std::to_string(intercepto);
    } else {
        this -> expresion = std::to_string(pendiente) + "×" + x + " " + std::to_string(intercepto);
    }
}

std::string MCO::getExpresion()
{
    return this -> expresion;
}

long double MCO::getR()
{
    return this -> R2;
}

