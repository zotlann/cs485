#include "gauss.h"
#include "image_util.h"

float* Gauss1D(float s, int Hsize){
	float cst,tssq,x,sum;
	float* H = new float[Hsize];

	cst=1./(s*sqrt(2.0*pi));
	tssq=1./(2*s*s);
	sum = 0;
	for(int i = 0; i < Hsize; i++){
		x=(float)(i-Hsize/2);
		H[i]=(cst*exp(-(x*x*tssq)));
		sum += H[i];
	}
	
	//normalize the mask
	for(int i = 0; i < Hsize; i++){
		H[i] /= sum;
	}
	return H;
}


//Generates a normalized 2D gaussian array with sigma, of size Hsize.
float** Gauss2D(float sigma, int Hsize){
	float* H1D = Gauss1D(sigma,Hsize);
	float** H = new float*[Hsize];
	float sum  = 0;
	for(int i = 0; i < Hsize; i++){
		H[i] = new float[Hsize];
	}
	for(int i = 0; i < Hsize; i++){
		for(int j = 0; j < Hsize; j++){
			H[i][j] = H1D[i]*H1D[j];
			sum+=H[i][j];
		}
	}
	for(int i = 0; i < Hsize; i++){
		for(int j = 0; j < Hsize; j++){
			H[i][j] /= sum;
		}
	}
	return H;
}

float* smoothGraph(float* graph, int n, float sigma){
	int Hsize = 5*sigma;
	float* H = Gauss1D(sigma,Hsize);

	return correlateMask1DSignal(graph,n,H,Hsize);
}

int** smoothImage(int** image, int w, int h, float sigma){
	int** ret = new int*[w];
	for(int i = 0; i < w; i++){
		ret[i] = new int[h];
	}

	int Hsize = 5*sigma;
	float** H = Gauss2D(sigma,Hsize);
	
	return correlate2DSignal(image, w, h, H, Hsize);
}

int** smoothImageSeparated(int** image, int w, int h, float sigma){
	int** ret = new int*[w];
	for(int i = 0; i < w; i++){
		ret[i] = new int[h];
	}
	
	int Hsize = 5*sigma;
	float* H = Gauss1D(sigma,Hsize);
	
	return correlate2DSignalSeparated(image, w, h, H, Hsize, H, Hsize);
}
