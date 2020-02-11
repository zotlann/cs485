#include "image_io.h"
#include "graph_io.h"
#include "gauss.h"
#include <iostream>
#include <cstring>

bool parseCmdArgs(int argc, char** argv, char* &infile, char* &outfile, int &sigma){
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

float applyGMask(float* graph, int point, int n, float* H, int Hsize){
	int g_center = Hsize/2;
	int p = point - g_center;
	float ret = 0;
	for(int i = 0; i < Hsize; i++){
		if(p > 0 && p < n){
			ret += H[i]*graph[p];
		}
		p++;	
	}
	return ret;
}

float* correlate(float* graph, int n, float* H, int Hsize){
	float* ret = new float[n];
	for(int i = 0; i < n; i++){
		ret[i] = applyGMask(graph,i,n,H,Hsize);
	}
	return ret;
}

int main(int argc, char** argv){
	char* infile;
	char* outfile;
	int sigma;
	float* g_data;
	int n;
	
	if(!parseCmdArgs(argc, argv, infile, outfile, sigma)){
		return 1;
	}

	int Hsize = 5*sigma;
	float* H = new float[Hsize];
	Gauss((float)sigma,Hsize,H);
	g_data = ReadGraph(infile,n);
	float* g_out = correlate(g_data,n,H,Hsize);
	WriteGraph(outfile,g_out,n);
	
	return 0;
}
