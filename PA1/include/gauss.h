#ifndef GAUSS_H
#define GAUSS_H

#include <math.h>
#define pi 3.141592653589793

float* Gauss1D(float s, int Hsize);
float** Gauss2D(float sigma, int Hsize);
float applyMask1D(float* signal, int point, int n, float* H, int Hsize);
float* correlate1D(float* signal, int n, float* H, int Hsize);


#endif //GAUSS_H
