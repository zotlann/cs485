#include "graph_io.h"

float* ReadGraph(char* filename, int& n){
	std::ifstream graph_data;
	graph_data.open(filename);
	std::vector<float> data;
	float temp_float;
	while(graph_data >> temp_float){
		data.push_back(temp_float);
	}
	n = data.size();
	float* ret = new float[n];
	for(int i = 0; i < n; i++){
		ret[i] = data[i];
	}
	data.clear();
	return ret;	
}

void WriteGraph(char* filename, float* graph, int n){
	std::ofstream graph_file;
	graph_file.open(filename,std::ofstream::out | std::ofstream::trunc);
	for(int i = 0; i < n; i++){
		graph_file << graph[i] << std::endl;
	}
}
