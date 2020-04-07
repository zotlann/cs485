PA2 Part 1 Face Normalization
To build extract PA2_pb1.zip and enter the PA2_pb1/ directory and enter the
following commands
>mkdir build
>cp makefile build
>cd build
>make

This will result in an executable named normalize
normalize takes a single command line argument, a filepath for the
normalization config.
The normalization config is a .xml file with all the information for the
image, including the original and and post-transform feature locations.
Example config files are found in /assets/configs

Ex:
./normalize ../assets/configs/1.xml
Will load the config data in 1.xml and perform the normalization accordingly

The program outputs the A,x, and b matrices as console output and has 3 image
outputs.  normalized.pgm, rotated,pgm, and translated.pgm.  Because the code
for svd didn't work on my image matrices, the normalized image is incorrect;
however the rotated and translated images confirm that the transformations are
applied correctly.  More information about how and why this project doesn't
function correctly, along with some example output, can be found in the report
PA2_pb2_report.pdf

Examples of filtered images can be found in the report PA1_pb1_report.pdf

