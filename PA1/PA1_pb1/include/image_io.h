#ifndef IMAGEIO_H
#define IMAGEIO_H

#include <iostream>
#include <fstream>
#include <stdlib.h>

void ReadImage(char fname[], int*** fimage, int& M, int& N, int& Q);
void WriteImage(char fname[], int** fimage, int M, int N, int Q);

#endif //IMAGEIO_H 
