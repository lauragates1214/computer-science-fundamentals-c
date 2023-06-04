/*
    PROGRAM :  Credit
    AUTHOR  :  Laura Purcell-Gates
    EMAIL   :  <laurapurcellgates@gmail.com>

    CS50x 2023 Problem Set 1 Credit

    Credit is a program that prompts the user for a credit card number,
    then uses Luhn's algorithm to validate the card number as Visa, MasterCard,
    American Express or invalid.

    I also wrote it in Python as part of CS50x Problem Set 6
    (see Harvard-CS50-lab-problemsets-Python repository).

    Code fully written by me; no pre-filled CS50 code.

    Link to the problem set:
    https://cs50.harvard.edu/x/2023/psets/1/credit/  */


#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user for number
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);

    // calculate total1
    long number1 = number / 10;
    int digit;
    int digit1;
    int digit2;
    int total1 = 0;

    while (number1 > 1)
    {
        digit = (number1 % 10) * 2;
        if (digit > 9)
        {
            digit1 = digit % 10;
            digit2 = (digit / 10) % 10;
            digit = digit1 + digit2;
        }
        total1 = total1 + digit;
        number1 /= 100;
    }

    // calculate total2
    long number2 = number;
    int total2 = 0;
    while (number2 > 1)
    {
        digit = number2 % 10;
        total2 = total2 + digit;
        number2 /= 100;
    }

    // add total 1 to total2
    int final = total1 + total2;

    // check if mod 10 is 0. If no, INVALID, else if yes, run checks on number lengths and first digits
    int div13 = number / 10000000000000;
    int div15 = number / 1000000000000000;
    int div16 = number / 10000000000000000;
    int visa13 = number / 1000000000000;
    int amex = number / 10000000000000;
    int mc = number / 100000000000000;
    int visa16 = number / 1000000000000000;

    if (final % 10 == 0)
    {
        // check VISA 13-digit starting 4
        if (div13 <= 1 && visa13 == 4)
        {
            printf("VISA\n");
        }
        // check AMEX 15-digit starting 34 or 37
        else if (div15 <= 1 && (amex == 34 || amex == 37))
        {
            printf("AMEX\n");
        }
        // check MASTERCARD 16-digit starting 5
        else if (div16 <= 1 && (mc == 51 || mc == 52 || mc == 53 || mc == 54 || mc == 55))
        {
            printf("MASTERCARD\n");
        }
        // check VISA 16-digit starting 4
        else if (div16 <= 1 && visa16 == 4)
        {
            printf("VISA\n");
        }
        // if none of the above, INVALID
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}