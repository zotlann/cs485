#include "image_io.h"
#include "graph_io.h"
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
	int threshold;
	int** input_image;
	int** output_image;
	int w,h,q;
	
	if(!parseCmdArgs(argc, argv, infile, outfile, threshold)){
		return 1;
	}

	ReadImage(infile, &input_image, w, h, q);
	output_image = detectEdges(input_image, w, h, threshold);
	WriteImage(outfile, output_image, q, h, q);

	return 0;
}
