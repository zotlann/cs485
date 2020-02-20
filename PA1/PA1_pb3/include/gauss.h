#ifndef GAUSS_H
#define GAUSS_H

#include <math.h>
#define gpi 3.141592653589793

float* Gauss1D(float s, int Hsize);
float** Gauss2D(float sigma, int Hsize);
float* smoothGraph(float* graph, int n, float sigma);
int** smoothImage(int** image, int w, int h, float sigma);
int** smoothImageSeparated(int** image, int w, int h, float sigma);
int** downsample(int** image, int w, int h);
int*** GaussianPyramid(int ** image, int w, int h, float size, int n);
#endif //GAUSS_H
