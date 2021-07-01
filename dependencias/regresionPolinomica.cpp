#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>




//Método de eliminación de Gauss: eliminación hacia adelante.
void eliminacionGauss(double **A, double B[], int n) {
    double inv;
    for (int k = 0; k < n; k++) {
        for (int i = k + 1; i < n; i++) {
        inv = A[i][k] / A[k][k];
                for (int j = k; j < n; j++) {
                    A[i][j] = A[i][j] - inv*A[k][j];
                }
        B[i] = B[i] - inv*B[k];
        }
    }
}

//Método de eliminación de Gauss: sustitución inversa.
void sustitucionAtras(double **A, double B[], int n, double C[]) {
    double suma;
    C[n - 1] = B[n - 1] / A[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suma = 0;
        for (int j = i + 1; j < n; j++) {
            suma = suma + A[i][j] * C[j];
        }
        C[i] = (B[i] - suma) / A[i][i];
    }
}


//Regresión polinomial: recibe los datos de x y y, el grado del
//polinomio resultante y el número de datos.
long double regresionPolinomica(double x[], double y[], int n, int m, int evaluacion2) {
    double sum_x = 0, sum_xy = 0;
    int tamano = m + 1;
    double *solucion = new double[tamano];
    double **ecuaciones;

    ecuaciones = new double*[tamano];
    //Inicialización del arreglo bidimensional.
    for (int i = 0; i < tamano; i++) {
    ecuaciones[i] = new double[tamano];
    }

    //Cálculo de las sumatorias y armado del sistema.
    for (int i = 0; i < tamano; i++) {
        sum_xy = 0;
        
        for (int j = 0; j < n; j++){
            sum_xy += pow(x[j], i)*y[j];
            solucion[i] = sum_xy;
        }
        for (int j = 0; j < tamano; j++) {
            sum_x = 0;
            if (i == 0 && j == 0){
            ecuaciones[i][j] = n;
            }
            else 
            {
                for (int h = 0; h < n; h++){
                    sum_x += pow(x[h], (j + i));
                    ecuaciones[i][j] = sum_x;
                }
            }
        }
    }


    //Resolucion de sistemas de ecuaciones.
    eliminacionGauss(ecuaciones, solucion, tamano);

    double *x_vector = new double[tamano];


    sustitucionAtras(ecuaciones, solucion, tamano, x_vector);

    //Construcción de la ecuación final.
    std::cout << "Modelo: ";

    for (int i = 0; i < tamano; i++) {
        std::cout << x_vector[i];
        if (i != 0) {
            std::cout << "x^" << i;
        }
        if (i != tamano - 1) {
            std::cout << "+";
        }
    }


    //Cálculo de los errores
    double *e = new double[n];
    for (int i = 0; i < n; i++) {
        double y_calculada = 0;
        for (int j = tamano - 1; j >= 1; j--){
            y_calculada += x_vector[j] * (pow(x[i], j));
            y_calculada += x_vector[0];
            e[i] = pow(y[i] - y_calculada, 2);
        }
    }

    double sum_y = solucion[0];

    double sr = 0;
    double st = 0;
    for (int i = 0; i < n; i++) {
        sr += e[i];
        st += pow(y[i] - (sum_y / n), 2);
    }

    double err = sqrt(sr / (n - tamano));

    double r2 = (st - sr) / st;
      
    double r = sqrt(r2);
    
    
    
    //Desplegado de errores.
   /* std:: cout << "Error estandar de la estimacion: " << err << std::endl;
    std:: cout << "Coeficiente de determinacion: " << r2 << std::endl;
    std:: cout << "Coeficiente de correlacion: " << r << std::endl;
    std:: cout << std::endl;*/


    long double polinomica;

    for (int i = 0; i < tamano; i++) {
        polinomica=x_vector[i];
        if (i != 0) {
            polinomica+=pow(x_vector[i], i);
        }
    }

    return polinomica;
}

