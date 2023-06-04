/*
    PROGRAM :  Population Growth
    AUTHOR  :  Laura Purcell-Gates
    EMAIL   :  <laurapurcellgates@gmail.com>

    CS50x 2023 Lab 1 Population Growth

    Population Growth is a program that calculates the number of years
    required for a population to grow from a start size to an end size.

    Code fully written by me; no pre-filled CS50 code.

    Link to the lab:
    https://cs50.harvard.edu/x/2023/labs/1/  */


#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // Calculate number of years until we reach threshold
    int years = 0;
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }

    // Print number of years
    printf("Years: %i \n", years);
}
