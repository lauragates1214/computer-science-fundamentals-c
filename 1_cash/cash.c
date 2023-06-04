/*
    PROGRAM :  Cash
    AUTHOR  :  Laura Purcell-Gates
    EMAIL   :  <laurapurcellgates@gmail.com>

    CS50x 2023 Problem Set 1 Cash

    Cash is a program that prompts the user for the number of cents
    that a customer is owed and then prints the smallest number of
    coins with which that change can be made.

    I also wrote it in Python as part of CS50x Problem Set 6
    (see Harvard-CS50-lab-problemsets-Python repository).

    Code fully written by me; no pre-filled CS50 code.

    Link to the problem set:
    https://cs50.harvard.edu/x/2023/psets/1/cash/  */


#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // Prompt user for cents using "Change owed: "
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    // Calculate max quarters in change
    cents = cents / 25;
    return cents;
}

int calculate_dimes(int cents)
{
    // Calculate max dimes in remaining change
    cents = cents / 10;
    return cents;
}

int calculate_nickels(int cents)
{
    // Calculate max nickels in remaining change
    cents = cents / 5;
    return cents;
}

int calculate_pennies(int cents)
{
    // Calculate remaining change by cents for number of pennies
    cents = cents % 25 % 10 % 5;
    return cents;
}
