#include "image_util.h"

/*applyHorizontalMask2DSignal
 * applies the given 1d horizontal mask at point (x,y) in a given signal
 */
int applyHorizontalMask2DSignal(int** signal, int x, int y, int w, int h, float* H, int Hsize){
	int x_center = Hsize/2;
	int p_x = x - x_center;
	int p_y = y;
	float ret = 0;

	for(int i = 0; i < Hsize; i++){
		int x_sample = p_x;
		if(p_x < 0)
			x_sample = 0;
		if(p_x >= w)
			x_sample = w - 1;
		ret+=H[i]*signal[p_y][x_sample];
		p_x++;
	}

	return (int)ret;
}

/*applyVerticalMask2DSignal
 * applies the given 1d vertical mask at point (x,y) in a given signal
 */
int applyVerticalMask2DSignal(int** signal, int x, int y, int w, int h, float* H, int Hsize){
	int y_center = Hsize/2;
	int p_y = y - y_center;
	int p_x = x;
	float ret = 0;

	for(int i = 0; i < Hsize; i++){
		int y_sample = p_y;
		if(p_y < 0)
			y_sample = 0;
		if(p_y >= h)
			y_sample = h - 1;
		ret+=H[i]*signal[y_sample][p_x];
		p_y++;
	}

	return (int)ret;
}

/*apply2DMask2DSignal
 * applies the given 2D mask at point (x,y) in the given 2D signal
 */
int apply2DMask2DSignal(int** signal, int x, int y, int w, int h, float** H, int Hsize){
	int center = Hsize/2+1;
	int p_x = x - center;
	int p_y = y - center;

	float ret = 0;
	for(int i = 0; i < Hsize; i++){
		int x_sample = p_x;
		if(p_x < 0)
			x_sample = 0;
		if(p_x >= w)
			x_sample = w - 1;
		for(int j = 0; j < Hsize; j++){
			int y_sample = p_y;
			if(p_y < 0)
				y_sample = 0;
			if(p_y >= h)
				y_sample = h - 1;
			
			ret+=H[i][j]*signal[y_sample][x_sample];
			p_y++;
		}
		p_x++;
	}
	return (int) ret;
}

int** correlateHorizontalMask2DSignal(int** signal, int w, int h, float* H, int Hsize){
	int** ret = new int*[h];
	for(int i = 0; i < h; i++){
		ret[i] = new int[w];
	}
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			ret[i][j] = applyHorizontalMask2DSignal(signal,i,j,w,h,H,Hsize);
		}
	}
	return ret;
}

int** correlateVerticalMask2DSignal(int** signal, int w, int h, float* H, int Hsize){
	int** ret = new int*[h];
	for(int i = 0; i < h; i++){
		ret[i] = new int[w];
	}
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			ret[i][j] = applyVerticalMask2DSignal(signal,i,j,w,h,H,Hsize);
		}
	}
	return ret;
}

int** correlate2DSignal(int** signal, int w, int h, float** H, int Hsize){
	int** ret = new int*[h];
	for(int i = 0; i < h; i++){
		ret[i] = new int[w];
	}
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			ret[i][j] = apply2DMask2DSignal(signal,i,j,w,h,H,Hsize);
		}
	}
	return ret;
}

int** correlate2DSignalSeparated(int** signal, int w, int h, float* HX, int HXsize, float* HY, int HYsize){
	return correlateVerticalMask2DSignal(correlateHorizontalMask2DSignal(signal,w,h,HX,HXsize),w,h,HY,HYsize);
}
