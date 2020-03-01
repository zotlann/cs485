CC=g++
LIBS=

CXXFLAGS=-g -Wall -Wformat -Wno-deprecated 
LIBS = 

# .o Compilation
O_FILES=image_io.o graph_io.o gauss.o image_util.o

# Point to includes of local directories
INCLUDES=-I../include
all: blur blur_separated smooth_graph

blur: $(O_FILES) blur.o
	$(CC) $(CXXFLAGS) -o blur $(O_FILES) blur.o $(LIBS) #$(PATHI) $(PATHL)
blur_separated: $(O_FILES) blur_separated.o
	$(CC) $(CXXFLAGS) -o blur_separated $(O_FILES) blur_separated.o $(LIBS) #$(PATHI) $(PATHL)
smooth_graph: $(O_FILES) smooth_graph.o
	$(CC) $(CXXFLAGS) -o smooth_graph $(O_FILES) smooth_graph.o $(LIBS) #$(PATHI) $(PATHL)
blur.o: ../src/blur.cpp
	$(CC) $(CXXFLAGS) -c ../src/blur.cpp -o blur.o $(INCLUDES)
blur_separated.o: ../src/blur_separated.cpp
	$(CC) $(CXXFLAGS) -c ../src/blur_separated.cpp -o blur_separated.o $(INCLUDES)
smooth_graph.o: ../src/smooth_graph.cpp
	$(CC) $(CXXFLAGS) -c ../src/smooth_graph.cpp -o smooth_graph.o $(INCLUDES)
image_io.o: ../src/image_io.cpp
	$(CC) $(CXXFLAGS) -c ../src/image_io.cpp -o image_io.o $(INCLUDES)
graph_io.o: ../src/graph_io.cpp
	$(CC) $(CXXFLAGS) -c ../src/graph_io.cpp -o graph_io.o $(INCLUDES)
image_util.o: ../src/image_util.cpp
	$(CC) $(CXXFLAGS) -c ../src/image_util.cpp -o image_util.o $(INCLUDES)
gauss.o: ../src/gauss.cpp
	$(CC) $(CXXFLAGS) -c ../src/gauss.cpp -o gauss.o $(INCLUDES)
clean:
	-@if rm *.o OCV  2>/dev/null || true; then echo "Main Removed"; else echo "No Main"; fi
