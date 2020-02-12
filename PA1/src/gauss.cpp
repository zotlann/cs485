#include "gauss.h"
#include <iostream>
/* Create a one-dimensional Gaussian mask
 "H" of scale "s" (sigma) on "Hsize" pixels.

   The values of the mask are scaled so that the
 sum of mask values = 1.0 
*/
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


//returns the value of applying a mask to a signal centered around some point
float applyMask1D(float* signal, int point, int n, float* H, int Hsize){
	int g_center = Hsize/2;
	int p = point - g_center;
	float ret = 0;
	for(int i = 0; i < Hsize; i++){
		if(p > 0 && p < n){
			ret+=H[i]*signal[p];
		}
		p++;
	}
	return ret;
}

//applies a mask to every point over a 1d signal
float* correlate1D(float* signal, int n, float* H, int Hsize){
	float* ret = new float[n];
	for(int i = 0; i < n; i++){
		ret[i] = applyMask1D(signal,i,n,H,Hsize);
	}
	return ret;
}


//Generates a normalized 2D gaussian array with sigma, of size Hsize.
float** Gauss2D(float sigma, int Hsize){
	int center = Hsize/2;
	float sum = 0;
	float** H = new float*[Hsize];
	for(int i = 0; i < Hsize; i++){
		H[i] = new float[Hsize];
	}
	for(int i = 0; i < Hsize; i ++){
		for(int j = 0; j < Hsize; j++){
			float x = i - center;
			float y = j - center;
			float dist = sqrt(x*x+y*x);
			H[i][j] = exp(-(dist*dist)/(2*sigma*sigma));
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

