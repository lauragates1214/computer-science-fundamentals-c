/*
    PROGRAM :  Recover
    AUTHOR  :  Laura Purcell-Gates
    EMAIL   :  <laurapurcellgates@gmail.com>

    CS50x 2023 Problem Set 4 Recover

    Recover is a program that iterates over a forensic image of a memory card,
    looking for JPEG signatures and recovering the images.

    Code fully written by me; no pre-filled CS50 code apart from library inclusions
    and main function parameters.

    Link to the problem set:
    https://cs50.harvard.edu/x/2023/psets/4/recover  */


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// declare variables
const int BLOCK_SIZE = 512;
typedef uint8_t BYTE;

// recover function
int main(int argc, char *argv[])
{
    // check for correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image-file\n");
        return 1;
    }

    // open memory card; check that can be opened
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // create buffer to read into
    BYTE buffer[BLOCK_SIZE];

    // create pointer for output files
    FILE *new_img_file = NULL;

    // allocate memory for these filenames dynamically (7 + 1 for ###.jpg/0)
    char *filename = malloc(sizeof(char) * 8);

    // declare variable to keep track of jpegs counted for filenames
    int jpeg_count = 0;

    // repeat a process until reach end of card:
    // read 512 bytes into buffer (using fread)
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, input_file) == BLOCK_SIZE)
    {
        // if start of new JPEG:
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer [2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // if not first file, close prev file
            if (jpeg_count > 0)
            {
                fclose(new_img_file);
            }

            // start writing file ###.jpg
            // create filename
            sprintf(filename, "%03i.jpg", jpeg_count);

            // open that file
            new_img_file = fopen(filename, "w");

            // write from buffer into the new_img_file,
            // first checking that new_img_file pointer does not point to NULL
            if (new_img_file != NULL)
            {
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, new_img_file);
            }

            // increase jpeg_count to track jpeg numbers created/recovered
            jpeg_count++;
        }

        // if no match for first 4 bytes, and not first file, continue writing into current file
        else if (jpeg_count > 0)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, new_img_file);
        }
    }

    // free filename memory allocation
    free(filename);

    // close any remaining files, return 0
    fclose(new_img_file);
    fclose(input_file);

    return 0;
}