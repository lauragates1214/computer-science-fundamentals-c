/*
    PROGRAM :  Filter
    AUTHOR  :  Laura Purcell-Gates
    EMAIL   :  <laurapurcellgates@gmail.com>

    CS50x 2023 Problem Set 4 Filter

    Filter is a program that allows the user to apply grayscale, sepia, reflection, or
    blur filters to their images.

    I wrote all functions below; no pre-filled CS50 code apart from function names and parameters.

    Link to the problem set:
    https://cs50.harvard.edu/x/2023/psets/4/filter/less  */


#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // scan through pixels within image height
    for (int i = 0; i < height; i++)
    {
        // scan through pixels within image width
        for (int j = 0; j < width; j++)
        {
            // convert to grayscale by averaging rgb values to make them equal within each pixel
            // create float variable for rgb total for each pixel
            float rgb_total = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;

            // find average for each rgb value
            int average = (round)(rgb_total / 3.0);

            // assign new averaged value back into the pixel's rgb
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // scan through pixels within image height
    for (int i = 0; i < height; i++)
    {
        // scan through pixels within image width
        for (int j = 0; j < width; j++)
        {
            // declare sepia variables & convert rgb to sepia using the sepia algorithm
            int sepiaRed = (round)(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = (round)(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = (round)(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // cap resulting values at 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // assign sepia values back into image array
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // scan through image height pixels
    for (int i = 0; i < height; i++)
    {
        // scan through image width pixels first half, dividing w by 2 because of mirroring "fold"
        for (int j = 0; j < width / 2; j++)
        {
            // declare temporary variable to swap left half pixel into
            RGBTRIPLE tmp = image[i][j];

            // swap left half with right half
            image[i][j] = image[i][width - (j + 1)];

            // transfer tmp value into right half pixel
            image[i][width - (j + 1)] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // declare temporary variable to store average values of each pixel 3x3 box
    RGBTRIPLE tmp[height][width];

    // loop through image pixels height
    for (int i = 0; i < height; i++)
    {
        // loop through image pixels width
        for (int j = 0; j < width; j++)
        {
            // declare variables to hold sum of color values
            int sumRed, sumGreen, sumBlue;

            // initialize to 0
            sumRed = sumGreen = sumBlue = 0;

            // declare variable to keep track of adjacent pixels used in calcs, initialize to 0
            float pixel_number = 0.00;

            // scan 3x3 box of pixels by row
            for (int row = i - 1; row <= i + 1; row++)
            {
                // scan 3x3 box of pixels by column
                for (int column = j - 1; column <= j + 1; column++)
                {
                    // check for valid adjacent pixels
                    if (row < 0 || column < 0 || row >= height || column >= width)
                    {
                        // jump down out of this iteration of the loop
                        continue;
                    }

                    // add value of each pixel in 3x3 box to "total" floats
                    sumRed += image[row][column].rgbtRed;
                    sumGreen += image[row][column].rgbtGreen;
                    sumBlue += image[row][column].rgbtBlue;

                    // count pixel numbers (only valid pixels)
                    pixel_number++;
                }

                // average the 3x3 box and assign into temporary variable
                tmp[i][j].rgbtRed = round(sumRed / pixel_number);
                tmp[i][j].rgbtGreen = round(sumGreen / pixel_number);
                tmp[i][j].rgbtBlue = round(sumBlue / pixel_number);
            }
        }
    }

    // transfer tmp back into original image
    // loop through image height
    for (int i = 0; i < height; i++)
    {
        // loop through image width
        for (int j = 0; j < width; j++)
        {
            // transfer temp values back into image h&w values
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
        }
    }

    return;
}
