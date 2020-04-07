#include "image_io.h"
#include "sobel.h"
#include <iostream>
#include <cstring>

bool parseCmdArgs(int argc, char** argv, char* &infile, char* &outfile, int &threshold){
	char help_message[256];
	sprintf(help_message,"%s  -i [input_graph] -o [output_filename] -s [threshold]",argv[0]);
	if(argc<2){
		printf("%s",help_message);
	}
	for(int i = 1; i < argc; i++){
		if((strcmp(argv[i],"-i")==0)){
			infile = argv[i+1];
			i++;
		}
		else if((strcmp(argv[i],"-o")==0)){
			outfile = argv[i+1];
			i++;
		}
		else if((strcmp(argv[i],"-t")==0)){
			threshold = std::atoi(argv[i+1]);
			i++;
		}
	}
	if(infile == NULL){
		printf("No input file given, please pass an input file using the -i flag\n");
		return false;
	}
	if(outfile == NULL){
		printf("No output file given, please pass an output filename using the -o flag\n");
		return false;
	}
	if(threshold == 0){
		printf("No threshold vaue given, please pass a threshold value using the -s flag\n");
		return false;
	}
	return true;
}

int main(int argc, char** argv){
	
	char* infile;
	char* outfile;
	char* xgrad = new char[255];
	char* ygrad = new char[255];
	char* gradmag = new char[255];
	char* thresholded = new char[255];
	int threshold;
	int** input_image;
	int** output_image;
	int w,h,q;
	
	if(!parseCmdArgs(argc, argv, infile, outfile, threshold)){
		return 1;
	}
	strcpy(xgrad,outfile);strcpy(ygrad,outfile);strcpy(gradmag,outfile);strcpy(thresholded,outfile);
	strcat(xgrad,"_xgrad.pgm");strcat(ygrad,"_ygrad.pgm");strcat(gradmag,"_gradmagnitude.pgm");strcat(thresholded,"_thresholded.pgm");

	ReadImage(infile, &input_image, w, h, q);
	int** xgrad_image = horizontalGradient(input_image,w,h);
	int** ygrad_image = verticalGradient(input_image,w,h);
	int** gradmag_image = magnitudeImage(xgrad_image, ygrad_image, w, h);
	int** thresholded_image = thresholdImage(gradmag_image, w, h, threshold);
	WriteImage(xgrad, xgrad_image, w, h, q);
	WriteImage(ygrad, ygrad_image, w, h, q);
	WriteImage(gradmag, gradmag_image, w, h, q);
	WriteImage(thresholded, thresholded_image, w, h, q);

	return 0;
}
