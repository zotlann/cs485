CC=g++
LIBS=

CXXFLAGS=-g -Wall -Wformat -Wno-deprecated 
LIBS = 

# .o Compilation
O_FILES=main.o image_io.o graph_io.o gauss.o image_util.o

# Point to includes of local directories
INCLUDES=-I../include

all: $(O_FILES)
	$(CC) $(CXXFLAGS) -o pyramid $(O_FILES) $(LIBS) #$(PATHI) $(PATHL)

main.o: ../src/main.cpp
	$(CC) $(CXXFLAGS) -c ../src/main.cpp -o main.o $(INCLUDES)
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
