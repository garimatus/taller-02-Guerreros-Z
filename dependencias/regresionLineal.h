#include <vector>
#include <string>



class regresionLineal {
    public :
        regresionLineal(long int, std::vector<long long int>, std::vector<long long int>, const char*);
        void setExpresion(std::string);
        long double evaluar(long double);
        std::string getExpresion();
        long double getR();
    private :
        long int muestra;
        long double pendiente;
        long double R2;
        long double varianza_x;
        long double varianza_y;
        long double covarianza;
        std::vector<long long int> X;
        std::vector<long long int> Y;
        long double intercepto;
        long double prom_x;
        long double prom_y;
        std::string expresion;
        std::string x;
};

