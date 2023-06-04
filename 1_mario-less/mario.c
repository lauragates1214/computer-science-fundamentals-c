/*
    PROGRAM :  Mario Less
    AUTHOR  :  Laura Purcell-Gates
    EMAIL   :  <laurapurcellgates@gmail.com>

    CS50x 2023 Problem Set 1 Mario Less

    Mario Less is a program that prompts the user for an integer then prints
    a half pyramid with equivalent rows and columns using #.

    I also wrote it in Python as part of CS50x Problem Set 6
    (see Harvard-CS50-lab-problemsets-Python repository).

    Code fully written by me; no pre-filled CS50 code.

    Link to the problem set:
    https://cs50.harvard.edu/x/2023/psets/1/mario/less/  */


#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get height input from user
    int height;
    {
        do
        {
            height = get_int("Height: ");
        }
        while (height < 1 || height > 8);
    }
    //build a pyramid
    //declare integers i (rows) and j (columns)
    for (int i = 0; i < height; i++)
    {
        //add spaces
        for (int space = 0; space < height - i - 1; space++)
        {
            printf(" ");
        }
        //add hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        //new line
        printf("\n");
    }
}