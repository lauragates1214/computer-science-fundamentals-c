/*
    PROGRAM :  Speller
    AUTHOR  :  Laura Purcell-Gates
    EMAIL   :  <laurapurcellgates@gmail.com>

    CS50x 2023 Problem Set 5 Speller

    Speller is a program that implements a dictionary's functionality.

    My contributions to the code commented as LauraPG.

    Link to the problem set:
    https://cs50.harvard.edu/x/2023/psets/5/speller  */


#include <ctype.h>
#include "dictionary.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// LauraPG: Choose number of buckets in hash table
const unsigned int N = 26;

// LauraPG: declare new global variables
// LauraPG: counter initialized to 0 so that returns 0 if load unsuccessful
unsigned int counter = 0;
unsigned int hashValue;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // LauraPG: obtain hash value of word
    hashValue = hash(word);

    // LauraPG: set trav pointer to head of that linked list
    node *trav = table[hashValue];

    // LauraPG: compare word with words in that linked list, until reach NULL
    while (trav != NULL)
    {
        if (strcasecmp(word, trav->word) == 0)
        {
            return true;
        }
        trav = trav->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // LauraPG: Write hash function - word ascii total
    // LauraPG: declare temporary variable to store word ascii values
    int hashTemp = 0;

    // LauraPG: loop through word string, adding ascii values (uppercase)
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hashTemp += toupper(word[i]);
    }
    // LauraPG: divide by N until less than N
    while (hashTemp > N)
    {
        hashTemp /= N;
    }
    // LauraPG: return hash value
    return hashTemp;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // LauraPG: use fopen() to open dictionary file
    FILE *dictionaryFile = fopen(dictionary, "r");

    // LauraPG: return false if file can't be opened, and an error message
    if (dictionaryFile == NULL)
    {
        printf("Cannot open %s\n", dictionary);
        return false;
    }

    // LauraPG: declare word variable
    char word[LENGTH + 1];

    // LauraPG: scan through dictionary until EOF using fscanf(file, "%s", word)
    while (fscanf(dictionaryFile, "%s", word) != EOF)
    {
        // LauraPG: create new node for each word - allocate memory
        node *newNode = malloc(sizeof(node));

        // LauraPG: return false if pointer points to NULL to avoid seg fault
        if (newNode == NULL)
        {
            return false;
        }

        // LauraPG: copy word from dictionary file into newNode
        strcpy(newNode->word, word);

        // LauraPG: run hash function to return hash value for word
        hashValue = hash(word);

        // LauraPG: link newNode to hash table at location returned by hash function
        newNode->next = table[hashValue];

        // LauraPG: point hashValue to newNode to make it head of linked list
        table[hashValue] = newNode;

        // LauraPG: increase counter for wordcount size function
        counter++;
    }
    // LauraPG: close file, return true
    fclose(dictionaryFile);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // LauraPG
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // LauraPG: iterate through buckets in hash table
    for (int i = 0; i < N; i++)
    {
        // LauraPG: set trav pointer to head of linked list
        node *trav = table[i];

        // LauraPG: set temp pointer to trav
        node *temp = trav;

        // LauraPG: while loop until trav reaches NULL
        while (trav != NULL)
        {
            // LauraPG: move trav to next node
            trav = trav->next;

            // LauraPG: free temp
            free(temp);

            // LauraPG: set temp to trav
            temp = trav;
        }
    }
    // LauraPG
    return true;
}
