/*
    PROGRAM :  Volume
    AUTHOR  :  Laura Purcell-Gates
    EMAIL   :  <laurapurcellgates@gmail.com>

    CS50x 2023 Lab 4 Volume

    Volume is a program that modifies the volume of an audio file.

    My contributions to the code commented as LauraPG (start at line 50).

    Link to the lab:
    https://cs50.harvard.edu/x/2023/labs/4/  */


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // LauraPG contributions below assisted by CS50 walkthrough
    // LauraPG: Copy header from input file to output file
    // LauraPG: create buffer to temporarily store the header from input file
    uint8_t header[HEADER_SIZE];

    // LauraPG: use fread to read from input file copying into buffer
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);

    // LauraPG: use fwrite to write from buffer into output file
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);


    // LauraPG: Read samples from input file and write updated data to output file
    // LauraPG: create buffer to temporarily store 2-byte samples (one at a time) from input file
    int16_t buffer;

    // LauraPG: create while loop for whenever there's data to be read, one 2-byte sample at a time
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // LauraPG: change volume by factor
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
