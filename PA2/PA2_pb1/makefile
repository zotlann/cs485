CC=g++
CXXFLAGS=-g -Wall -Wformat -std=c++0x  $(shell pkg-config --cflags opencv4)
LIBS = $(shell pkg-config --libs opencv4)

# .o Compilation
O_FILES=main.o svdcmp.o svbksb.o solve_system.o tinyxml2.o image_io.o util.o

# Point to includes of local directories
INCLUDES=-I../include

all: $(O_FILES)
	$(CC) $(CXXFLAGS) -o normalize $(O_FILES) $(LIBS) #$(PATHI) $(PATHL)

main.o: ../src/main.cpp
	$(CC) $(CXXFLAGS) -c ../src/main.cpp -o main.o $(INCLUDES)

tinyxml2.o: ../src/tinyxml2.cpp
	$(CC) $(CXXFLAGS) -c ../src/tinyxml2.cpp -o tinyxml2.o $(INCLUDES)

image_io.o: ../src/image_io.cpp
	$(CC) $(CXXFLAGS) -c ../src/image_io.cpp -o image_io.o $(INCLUDES)
util.o: ../src/util.cpp
	$(CC) $(CXXFLAGS) -c ../src/util.cpp -o util.o
svdcmp.o: ../src/svdcmp.c
	gcc -c -g ../src/svdcmp.c 

svbksb.o: ../src/svbksb.c
	gcc -c -g ../src/svbksb.c

solve_system.o: svdcmp.o svbksb.o ../src/solve_system.c 
	gcc -c -g ../src/solve_system.c


clean:
	-@if rm *.o OCV  2>/dev/null || true; then echo "Main Removed"; else echo "No Main"; fi


