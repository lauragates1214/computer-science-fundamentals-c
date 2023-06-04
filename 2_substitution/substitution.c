/*
    PROGRAM :  Substitution
    AUTHOR  :  Laura Purcell-Gates
    EMAIL   :  <laurapurcellgates@gmail.com>

    CS50x 2023 Problem Set 2 Substitution

    Substitution is a program that encrypts messages using a sustitution cipher.

    My contributions to the code commented as LauraPG (fully written by me,
    no pre-filled CS50 code apart from library inclusions and main function parameters)

    Link to the problem set:
    https://cs50.harvard.edu/x/2023/psets/2/substitution  */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// LauraPG: declare function key_check
bool key_check(string s);

int main(int argc, string argv[])
{
    // LauraPG: check for correct number of input arguments; call key_check
    if (argc != 2 || key_check(argv[1]) == false)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        printf("Good key!\n");
    }

}

// LauraPG: define function key_check
bool key_check (string s)
{
    // LauraPG: check string length 26
    if (strlen(s) != 26)
    {
        return false;
    }

    // LauraPG: check alpha
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}