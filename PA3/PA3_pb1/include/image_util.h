#ifndef IMAGE_UTIL_H
#define IMAGE_UTIL_H

float applyMask1DSignal(float* signal, int point, int n, float* H, int Hsize);
int applyHorizontalMask2DSignal(int** signal, int x, int y, int w, int h, float* H, int Hsize);
int applyVerticalMask2DSignal(int** signal, int x, int y, int w, int h, float* H, int Hsize);
int apply2DMask2DSignal(int** signal, int x, int y, int w, int h, float** H, int Hsize);
float* correlateMask1DSignal(float* signal, int n, float* H, int Hsize);
int** correlateHroziontalMask2DSignal(int** signal, int w, int h, float* H, int Hsize);
int** correlateVerticalMask2DSignal(int** signal, int w, int h, float* H, int Hsize);
int** correlate2DSignal(int** signal, int w, int h, float** H, int Hsize);
int** correlate2DSignalSeparated(int** signal, int w, int h, float* HX, int HXsize, float* HY, int HYsize);

#endif //IMAGE_UTIL_H
