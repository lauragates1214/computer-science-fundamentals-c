/*
    PROGRAM :  Recover
    AUTHOR  :  Laura Purcell-Gates
    EMAIL   :  <laurapurcellgates@gmail.com>

    CS50x 2023 Problem Set 4 Recover

    Recover is a program that iterates over a forensic image of a memory card,
    looking for JPEG signatures and recovering the images.

    My contributions to the code commented as LauraPG (fully written by me,
    no pre-filled CS50 code apart from library inclusions and main function parameters)

    Link to the problem set:
    https://cs50.harvard.edu/x/2023/psets/4/recover  */


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// LauraPG: declare variables
const int BLOCK_SIZE = 512;
typedef uint8_t BYTE;

// recover function
int main(int argc, char *argv[])
{
    // LauraPG: check for correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image-file\n");
        return 1;
    }

    // LauraPG: open memory card; check that can be opened
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // LauraPG: create buffer to read into
    BYTE buffer[BLOCK_SIZE];

    // LauraPG: create pointer for output files
    FILE *new_img_file = NULL;

    // LauraPG: allocate memory for these filenames dynamically (7 + 1 for ###.jpg/0)
    char *filename = malloc(sizeof(char) * 8);

    // LauraPG: declare variable to keep track of jpegs counted for filenames
    int jpeg_count = 0;

    // LauraPG: repeat a process until reach end of card:
    // LauraPG: read 512 bytes into buffer (using fread)
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, input_file) == BLOCK_SIZE)
    {
        // LauraPG: if start of new JPEG:
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer [2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // LauraPG: if not first file, close prev file
            if (jpeg_count > 0)
            {
                fclose(new_img_file);
            }

            // LauraPG: start writing file ###.jpg
            // LauraPG: create filename
            sprintf(filename, "%03i.jpg", jpeg_count);

            // LauraPG: open that file
            new_img_file = fopen(filename, "w");

            // LauraPG: write from buffer into the new_img_file,
            // LauraPG: first checking that new_img_file pointer does not point to NULL
            if (new_img_file != NULL)
            {
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, new_img_file);
            }

            // LauraPG: increase jpeg_count to track jpeg numbers created/recovered
            jpeg_count++;
        }

        // LauraPG: if no match for first 4 bytes, and not first file, continue writing into current file
        else if (jpeg_count > 0)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, new_img_file);
        }
    }

    // LauraPG: free filename memory allocation
    free(filename);

    // LauraPG: close any remaining files, return 0
    fclose(new_img_file);
    fclose(input_file);

    return 0;
}