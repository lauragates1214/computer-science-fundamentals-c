/*
    PROGRAM :  Readability
    AUTHOR  :  Laura Purcell-Gates
    EMAIL   :  <laurapurcellgates@gmail.com>

    CS50x 2023 Problem Set 2 Readability

    Readability is a program that calculates the approximate grade
    reading level for a text using the Coleman-Liau index.

    My contributions to the code commented as LauraPG (fully written by me;
    no pre-filled CS50 code)

    Link to the problem set:
    https://cs50.harvard.edu/x/2023/psets/2/readability  */

#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// LauraPG: declare count_letters function
int count_letters(string text);

// LauraPG: declare count_words function
int count_words(string text);

// LauraPG: declare count_sentences function
int count_sentences(string text);

int main(void)
{
    // LauraPG: prompt user for text input
    string text = get_string("Text: ");

    // LauraPG: call count_letters function
    int total_letters = count_letters(text);

    // LauraPG: call count_words function
    int total_words = count_words(text);

    // LauraPG: call count_sentences function
    int total_sentences = count_sentences(text);

    // LauraPG: calculate L (avg number of letters per 100 words)
    float L = (((float) total_letters / (float) total_words) * 100);

    // LauraPG: calculate S (avg number of sentences per 100 words)
    float S = (((float) total_sentences / (float) total_words) * 100);

    // LauraPG: run Coleman-Liau index: index = 0.0588 * L - 0.296 * S - 15.8
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // LauraPG: print grade level
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
}

// LauraPG: define count_letters function
int count_letters(string text)
{
    // LauraPG: initialize lettercount to 0
    int lettercount = 0;

    // LauraPG: for loop to run through each character in text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // LauraPG: check for alpha
        if (isalpha(text[i]))
        {
            // LauraPG: count letters, assign to letter_count
            lettercount++;
        }
    }
    // LauraPG: return letter_count
    return lettercount;
}

// LauraPG: define count_words function
int count_words(string text)
{
    // LauraPG: initialize wordcount to 0
    int wordcount = 0;

    // LauraPG: count words using ASCII 32 [space] to mark word endings, +1 (bc final word will end with punctuation)
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((int) text[i] == 32)
        {
            wordcount++;
        }
    }

    // LauraPG: add 1 to wordcount (for final word)
    wordcount = wordcount + 1;

    // LauraPG: return wordcount
    return wordcount;
}

// LauraPG: define count_sentences function
int count_sentences(string text)
{
    // LauraPG: initialize sentencecount to 0
    int sentencecount = 0;

    // LauraPG: count sentences using ".", "!" or "?" as stopping points
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentencecount++;
        }
    }

    // LauraPG: return sentencecount
    return sentencecount;
}