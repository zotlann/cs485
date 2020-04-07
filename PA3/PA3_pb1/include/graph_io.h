#ifndef GRAPHIO_H
#define GRAPHIO_H

#include <iostream>
#include <fstream>
#include <vector>


float* ReadGraph(char* filename, int& n);
void WriteGraph(char* filename, float* graph, int n);
#endif //GRAPHIO_H
