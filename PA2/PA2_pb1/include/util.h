#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include "tinyxml2.h"
//#include <opencv4/opencv2/opencv.hpp>

struct Coordinate{
	int x,y;
};
struct Config{
	char* infile;
	char* outfile;
	int n_points;
	Coordinate* actual;
	Coordinate* normalized;
};

void getInterestPoints(char*,Config*);
float** getMatrixA(Config* cfg);
float* getMatrixB(Config* cfg);
float* getX(Config* cfg);
int** applyTransform(int** input_image, int w, int h, int new_w, int new_h, float* X);
void printArr(float**,int,int);
void printArr(float*,int);

#endif //UTIL_H
