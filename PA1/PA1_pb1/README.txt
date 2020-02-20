PA1_pb1 Gaussian Filters
To build extract PA1_pb1.zip and enter the PA1_pb1/ directory and enter the
following commands
>mkdir build
>cp makefile build
>cd build
>make

This will compile 3 separate programs: blur, blur_separated, and smooth_graph
these three programs all take the same command line arguments as follows
-s [sigma] -i [input_filepath] -o [output_filepath]
where sigma is an integer, the input file path is the relative filepath to the
image/graph you want to smooth, and output_filepath is the desired filepath
for the blurred image/graph.

Ex:
./blur -s 1 -i ../assets/lenna.pgm -o lenna.pgm

Will use the 2D Gaussian filter on the image ../assets/lenna.pgm and output
the blurred image in the current directory with the name lenna.pgm

smooth_graph accepts a file with a list of floats each on a new line, an
example graph is found in /assets/Rect_128.txt 
It outputs a similar file after applying the gaussian filter created using
sigma with mask size 5*sigma. 
These graphs can be viewed using gnuplot to verify the filter was applied
correctly

blur accepts a .pgm image file, blurs it with a 2D gaussian kernel using 2D
correlation and outputs the resulting image.  Example images can be found in
the assets folder, and the output images can be viewed using any image viewer
that accepts .pgm files.

blur_separated functions identically to blur; however, the correlation is
doign using 2 1D separated gaussian kernels and correlating in each direction
separately.

Examples of filtered images can be found in the report PA1_pb1_report.pdf

