/*
    PROGRAM :  Scrabble
    AUTHOR  :  Laura Purcell-Gates
    EMAIL   :  <laurapurcellgates@gmail.com>

    CS50x 2023 Lab 2 Scrabble

    Scrabble is a program that determines which of two Scrabble words is worth more.

    My contributions to the code commented as LauraPG (wrote compute_score function starting at line 51).

    Link to the lab:
    https://cs50.harvard.edu/x/2023/labs/2/  */


#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // LauraPG: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // LauraPG: Compute and return score for string
    // LauraPG: create int variable wordscore, initialize to 0
    int wordscore = 0;

    // LauraPG: create for loop to go through each letter of word input
    for (int i = 0; i < strlen(word); i++)
    {
        // LauraPG: check for alpha
        if (isalpha(word[i]))
        {
            // LauraPG: convert letters to uppercase and offset to set A (65) to 0 in ASCII
            int letter_convert = toupper(word[i]) - 'A';

            // LauraPG: add up the points, assign to wordscore
            wordscore += POINTS[letter_convert];
        }
    }
    // LauraPG: return wordscore
    return wordscore;
}
