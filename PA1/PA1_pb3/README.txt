PA1_pb3 Gaussian Pyramid
To build extract PA1_pb3.zip and enter the PA1_pb3/ directory and enter the
following commands
>mkdir build
>cp makefile build
>cd build
>make

This will compile a program called pyramid
This program will take in two command line arguments
-s [sigma] -i [input_filepath] -o [output_filename] -n [layers]
where sigma is an integer, n is an integer for hte amount of layers of the 
pyramid you want calculated and output,
the input file path is the relative filepath to the
image/graph you want to smooth, and output_filepath is the desired filename
for each of the images in the pyramid.
program.
$(output_filename)_stepN.pgm for each step in the pyramid.

Ex:
./pyramid -s 1 -n 3 -i ../assets/lenna.pgm -o lenna
this will output the three images
lenna_step1.pgm
lenna_step2.pgm
lenna_step3.pgm

which can be viewed by using an image viewer that accepts .pgm images.

Examples of the output can be found using the lenna image, s = 1, n = 3, can
be found in the report PA1_pb3_report.pdf
