#include "sobel.h"

int** horizontalGradient(int** image, int w, int h){
	float* Gx = new float[3];
	Gx[0]=1;Gx[1]=0;Gx[2]=-1;
	float* Gy = new float[3];
	Gy[0]=1;Gy[1]=2;Gy[2]=1;
	return correlate2DSignalSeparated(image, w, h, Gx, 3, Gy, 3);
}

int** verticalGradient(int** image, int w, int h){
	float* Gx = new float[3];
	Gx[0]=1;Gx[1]=2;Gx[2]=1;
	float* Gy = new float[3];
	Gy[0]=1;Gy[1]=0;Gy[2]=-1;
	return correlate2DSignalSeparated(image, w, h, Gx, 3, Gy, 3);
}

int** magnitudeImage(int** i1, int** i2, int w, int h){
	int** ret = new int*[h];
	for(int i = 0; i < h; i++){
		ret[i] = new int[w];
	}

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			int x = i1[i][j];
			int y = i2[i][j];
			ret[i][j] = sqrt(x*x+y*y);
		}
	}
	return ret;
}

int** thresholdImage(int** image, int w, int h, int threshold){
	int** ret = new int*[h];
	for(int i = 0; i < h; i++){
		ret[i] = new int [w];
	}
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(image[i][j] > threshold){
				ret[i][j] = 255;
			}
		}
	}
	return ret;
}

int** detectEdges(int** image, int w, int h, int threshold){
	return thresholdImage(magnitudeImage(verticalGradient(image,w,h),horizontalGradient(image,w,h),w,h),w,h,threshold);
}
