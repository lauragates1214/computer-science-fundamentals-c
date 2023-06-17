/*
    PROGRAM :  Readability
    AUTHOR  :  Laura Purcell-Gates
    EMAIL   :  <laurapurcellgates@gmail.com>

    CS50x 2023 Problem Set 2 Readability

    Readability is a program that calculates the approximate grade
    reading level for a text using the Coleman-Liau index.

    I also wrote it in Python as part of CS50x Problem Set 6
    (see Harvard-CS50-labs-problemsets-Python repository).

    Code fully written by me; no pre-filled CS50 code.

    Link to the problem set:
    https://cs50.harvard.edu/x/2023/psets/2/readability  */


#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// declare count_letters function
int count_letters(string text);

// declare count_words function
int count_words(string text);

// declare count_sentences function
int count_sentences(string text);

int main(void)
{
    // prompt user for text input
    string text = get_string("Text: ");

    // call count_letters function
    int total_letters = count_letters(text);

    // call count_words function
    int total_words = count_words(text);

    // call count_sentences function
    int total_sentences = count_sentences(text);

    // calculate L (avg number of letters per 100 words)
    float L = (((float) total_letters / (float) total_words) * 100);

    // calculate S (avg number of sentences per 100 words)
    float S = (((float) total_sentences / (float) total_words) * 100);

    // run Coleman-Liau index: index = 0.0588 * L - 0.296 * S - 15.8
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // print grade level
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

// define count_letters function
int count_letters(string text)
{
    // initialize lettercount to 0
    int lettercount = 0;

    // for loop to run through each character in text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // check for alpha
        if (isalpha(text[i]))
        {
            // count letters, assign to letter_count
            lettercount++;
        }
    }
    // return letter_count
    return lettercount;
}

// define count_words function
int count_words(string text)
{
    // initialize wordcount to 0
    int wordcount = 0;

    // count words using ASCII 32 [space] to mark word endings, +1 (bc final word will end with punctuation)
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((int) text[i] == 32)
        {
            wordcount++;
        }
    }

    // add 1 to wordcount (for final word)
    wordcount = wordcount + 1;

    // return wordcount
    return wordcount;
}

// define count_sentences function
int count_sentences(string text)
{
    // initialize sentencecount to 0
    int sentencecount = 0;

    // count sentences using ".", "!" or "?" as stopping points
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentencecount++;
        }
    }

    // return sentencecount
    return sentencecount;
}