#include "image_io.h"
#include "graph_io.h"
#include "gauss.h"
#include <iostream>
#include <cstring>
#include <string>

bool parseCmdArgs(int argc, char** argv, char* &infile, char* &outfile, int &sigma, int &n){
	char help_message[256];
	sprintf(help_message,"%s  -i [input_graph] -o [output_filename] -s [sigma]",argv[0]);
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
		else if((strcmp(argv[i],"-s")==0)){
			sigma = std::atoi(argv[i+1]);
			i++;
		}
		else if ((strcmp(argv[i],"-n")==0)){
			n = std::atoi(argv[i+1]);
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
	if(sigma == 0){
		printf("No sigma vaue given, please pass a sigma value using the -s flag\n");
		return false;
	}
	return true;
}

int main(int argc, char** argv){
	
	char* infile;
	char* outfile;
	int sigma;
	int** input_image;
	int** output_image;
	int w,h,q,n;
	
	if(!parseCmdArgs(argc, argv, infile, outfile, sigma, n)){
		return 1;
	}
	std::string out(outfile);

	ReadImage(infile, &input_image, w, h, q);
	int*** pyramid = GaussianPyramid(input_image, w, h, sigma, 4);
	std::string filename = out + "_step1.pgm";
	char* temp = new char[255];
	strcpy(temp,filename.c_str());
	WriteImage(temp, pyramid[0], w, h, q);
	for(int i = 1; i < n; i++){
		std::string filename = out + "_step" + std::to_string(i+1) + ".pgm";
		char* temp = new char[255];
		strcpy(temp,filename.c_str());
		WriteImage(temp, pyramid[i], w/(2*i), h/(2*i), q);
	}


	return 0;
}
