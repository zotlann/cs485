#ifndef SOBEL_H
#define SOBEL_H

#include "image_util.h"
#include <math.h>

int** horizontalGradient(int** image, int w, int h);
int** verticalGradient(int** image, int w, int h);
int** magnitudeImage(int** i1, int** i2, int w, int h);
int** thresholdImage(int** image, int w, int h, int threshold);
int** detectEdges(int** image, int w, int h, int threshold);

#endif //SOBEL_H

