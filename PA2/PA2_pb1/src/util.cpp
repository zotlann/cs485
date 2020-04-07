#include "util.h"

extern "C" void solve_system(int,int,float**,float*,float*);


void getInterestPoints(char* filename, Config* cfg){
	cfg->infile = new char[256];
	strcpy(cfg->infile,"../assets/1.pgm");
	cfg->outfile = new char[256];
	strcpy(cfg->outfile,"normalized.pgm");
	cfg->n_points = 4;
	cfg->actual = new Coordinate[4];
	cfg->actual[0] = {26,51};
	cfg->actual[1] = {64,50};
	cfg->actual[2] = {46,69};
	cfg->actual[3] = {46,89};
	cfg->normalized = new Coordinate[4];

	cfg->normalized[0] = {10,20};
	cfg->normalized[1] = {38,20};
	cfg->normalized[2] = {46,69};
	cfg->normalized[3] = {24,28};
/*	tinyxml2::XMLDocument doc;
	tinyxml2::XMLError file_loaded = doc.LoadFile(filename);
	if(file_loaded != tinyxml2::XML_SUCCESS){
		throw std::logic_error("Invalid file\n");
	}
	tinyxml2::XMLElement* config = doc.FirstChildElement("config"); 
	tinyxml2::XMLElement* element = NULL;

	//set the input filename
	if((element = config->FirstChildElement("infile"))){
		cfg->infile = new char[256];
		strcpy(cfg->infile, element->GetText());
	}
	//set the output filename
	if((element = config->FirstChildElement("outfile"))){
		cfg->outfile = new char[256];
		strcpy(cfg->outfile, element->GetText());
	}
	//set the number of points
	if((element = config->FirstChildElement("n_points"))){
		cfg->n_points = new int;
		int n = element->Int64Text();
		*cfg->n_points = n;
		cfg->actual = new Coordinate[n];
		cfg->normalized = new Coordinate[n];
	}

	//set up the points
	if((element = config->FirstChildElement("points"))){
		int i = 0;
		if((element = element->FirstChildElement())){
			tinyxml2::XMLElement* coord = element;
			if((coord = element->FirstChildElement("x"))){
				cfg->actual[i].x = coord->Int64Text();
			}
			if((coord = element->FirstChildElement("y"))){
				cfg->actual[i].y = coord->Int64Text();
			}
			if((coord = element->FirstChildElement("xf"))){
				cfg->normalized[i].x = coord->Int64Text();
			}
			if((coord = element->FirstChildElement("yf"))){
				cfg->normalized[i].y = coord->Int64Text();
			}
			i++;
			while((element = element->NextSiblingElement())){
				if(i >= *cfg->n_points){
					throw std::logic_error("Too many points defined\n");
				}
				tinyxml2::XMLElement* coord = element;
				if((coord = element->FirstChildElement("x"))){
					cfg->actual[i].x = coord->Int64Text();
				}
				if((coord = element->FirstChildElement("y"))){
					cfg->actual[i].y = coord->Int64Text();
				}
				if((coord = element->FirstChildElement("xf"))){
					cfg->normalized[i].x = coord->Int64Text();
				}
				if((coord = element->FirstChildElement("yf"))){
					cfg->normalized[i].y = coord->Int64Text();
				}
				i++;
			}
		}
		if(i < *cfg->n_points - 1){
			throw std::logic_error("Not enough points defined\n");
		}

	}
*/
}

float** getMatrixA(Config* cfg){
	float** ret = new float*[cfg->n_points*2+1];
	for(int i = 0; i < cfg->n_points*2+1; i++){
		ret[i] = new float[7];
	}
	for(int i = 0; i < cfg->n_points*2; i+=2){
		int j = i/2;
		ret[i][0] = cfg->actual[j].x;
		ret[i][1] = cfg->actual[j].y;
		ret[i][2] = 1;
		ret[i][3] = 0;
		ret[i][4] = 0;
		ret[i][5] = 0;
		ret[i+1][0] = 0;
		ret[i+1][1] = 0;
		ret[i+1][2] = 0;
		ret[i+1][3] = cfg->actual[j].x;
		ret[i+1][4] = cfg->actual[j].y;
		ret[i+1][5] = 1;
	}
	return ret;
}

float* getMatrixB(Config* cfg){
	float* ret = new float[cfg->n_points*2+1];
	for(int i = 0; i < cfg->n_points*2; i+=2){
		int j = i/2;
		ret[i] = cfg->normalized[j].x;
		ret[i+1] = cfg->normalized[j].y;
	}
	return ret;
}

float* getX(Config* cfg){
	float** a = getMatrixA(cfg);
	float*  b = getMatrixB(cfg);
	int m = cfg->n_points*2;
	int n = 6;
	std::cout << "A: " << std::endl;
	printArr(a,m,n);
	std::cout << "B: " << std::endl;
	printArr(b,m);

	/*
	opencv version 
	cv::Mat A = cv::Mat(m,n,CV_32FC1,a);
	cv::Mat B = cv::Mat(m,1,CV_32FC1,b);
	cv::Mat X = cv::Mat(n,1,CV_32FC1);
	cv::solve(A,B,X,cv::DECOMP_SVD);
	return X.ptr<float>(0);*/
	
	//clase code version
	float* x = new float[n+1];
	solve_system(m,n,a,x,b);
	std::cout << "x: " << std::endl;
	printArr(x,n);
	return x;
}

int** applyTransform(int** input_image, int w, int h, int new_w, int new_h, float* X){
	float k11 = X[0];
	float k12 = X[1];
	float k13 = X[2];
	float k21 = X[3];
	float k22 = X[4];
	float k23 = X[5];
	
	int x,y;
	x = y = 0;

	int** ret = new int*[new_h];
	for(int i = 0; i < new_h; i++){
		ret[i] = new int[new_w];
	}
	for(int i = 0; i < new_h; i++){
		for(int j = 0; j < new_w; j++){
			ret[i][i] = 0;
		}
	}

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			x = k11*j + k12*i + k13;
			y = k21*j + k22*i + k23;
			if((x>=0&&x<new_w)&&(y>=0&&y<new_h)){
				ret[y][x] = input_image[i][j];
			}
		}
	}

	return ret;
}

void printArr(float** arr, int w, int h){
	for(int i = 0; i < w; i++){
		for(int j = 0; j < h; j++){
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void printArr(float* arr, int n){
	for(int i = 0; i < n; i++){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

