#include <iostream>
#include <cstring>
#include "tinyxml2.h"
#include "image_io.h"
#include "util.h"
//#include <opencv4/opencv2/opencv.hpp>

extern "C" void solve_system(int,int,float**,float*,float*);

int main(int argc, char** argv){
	if(argc != 2){
		std::cout << "Invalid command line arguments given, please pass in just the filename for the .xml image normalization config file\n";
		return 1;
	}
	Config* cfg = new Config;
	getInterestPoints(argv[1],cfg);
	

	float test_a[4][4] = { {1,2,3,0},
			       {4,5,6,0},
			       {7,8,9,0},
			       {0,0,0,0}};
	float test_b[4] = {1,2,3,0};
	float* temp[4] = {test_a[0],test_a[1],test_a[2],test_a[3]};
	float** test_a_ptr = temp;
	float* test_b_ptr = test_b;
	float* test_x = new float[4];
	std::cout << "Confirmations that the svd code works on a simple example: " << std::endl;
	std::cout << "A: " << std::endl;
	printArr(test_a_ptr,3,3);
	std::cout << "b: " << std::endl;
	printArr(test_b_ptr,3);
	std::cout << "x: " << std::endl;
	solve_system(3,3,test_a_ptr,test_x,test_b_ptr);
	printArr(test_x,3);

	float* x = getX(cfg);

	int** input_image;
	int** normalized_image;
	int** rotated_image;
	int** translated_image;
	int w,h,q;
	float r[6] = {0,1,0,1,0,0};
	float* rotate = r;
	float t[6] = {1,0,50,0,1,50}; 
	float* translate = t;
	ReadImage("../assets/1.pgm", &input_image, w, h, q);
	normalized_image = applyTransform(input_image, w, h,48,40,x);
	rotated_image = applyTransform(input_image,w,h,w,h,rotate);
	translated_image = applyTransform(input_image,w,h,w,h,translate);
	WriteImage("normalized.pgm", normalized_image, 48, 40, q);
	WriteImage("rotated.pgm", rotated_image,w,h,q);
	WriteImage("translated.pgm",translated_image,w,h,q);
	
	return 0;
}
