/*
    PROGRAM :  Bulbs
    AUTHOR  :  Laura Purcell-Gates
    EMAIL   :  <laurapurcellgates@gmail.com>

    CS50x 2023 Problem Set 2 Bulbs

    Bulbs is a program that converts user input message from text to binary
    using emoji art representing lightbulbs in on or off position.

    My contributions to the code commented as LauraPG (wrote main function).

    Link to the problem set:
    https://cs50.harvard.edu/x/2023/psets/2/bulbs  */
    

#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // LauraPG: prompt user for message using get_string
    string message = get_string("Message: ");

    // LauraPG: look through each character of the string
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        // LauraPG: convert each letter/symbol into its corresponding ASCII value
        int ascii = message[i];

        // LauraPG: convert ASCII value into binary
        // LauraPG: declare an array called binary where put each value as 0 first
        int binary[] = {0, 0, 0, 0, 0, 0, 0, 0};

        // LauraPG: use modulus operator to fill in array
        int j = 0;
        while (ascii > 0)
        {
            binary[j] = ascii % 2;
            ascii = ascii / 2;
            j++;
        }

        // LauraPG: flip array
        for (int bulb = BITS_IN_BYTE - 1; bulb >= 0; bulb--)
        {
            print_bulb(binary[bulb]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
