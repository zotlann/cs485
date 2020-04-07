PA1_pb2 Edge Detection
To build extract PA1_pb2.zip and enter the PA1_pb2/ directory and enter the
following commands
>mkdir build
>cp makefile build
>cd build
>make

This will compile a program called sobel
This program will take in two command line arguments
-t [threshold] -i [input_filepath] -o [output_filename]
where threshold is an integer, the input file path is the relative filepath to the
image/graph you want to smooth, and output_filepath is the desired filename
for the gradient and magnitude images. Four images will be output from the
program.
$(output_filename)_xgrad.pgm for the gradient image in the x direction
$(output_filename)_ygrad.pgm for the gradient image in the y direction
$(output_filename)_gradmagnitude.pgm for the gradient magnitude image
$(output_filename)_thresholded.pgm for the edge image by thresholding using
the given threshold.

Ex:
./sobel -s 50 -i ../assets/lenna.pgm -o lenna
this will output the four images
lenna_xgrad.pgm
lenna_ygrad.pgm
lenna_gradmagnitude.pgm
lenna_thresholded.pgm

which can be viewed by using an image viewer that accepts .pgm images.

Examples of gradient images can be found in the report PA1_pb2_report.pdf

