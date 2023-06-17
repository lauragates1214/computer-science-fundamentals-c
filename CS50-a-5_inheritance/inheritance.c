/*
    PROGRAM :  Inheritance
    AUTHOR  :  Laura Purcell-Gates
    EMAIL   :  <laurapurcellgates@gmail.com>

    CS50x 2023 Lab 5 Inheritance

    Inheritance is a program that simulates genetic inheritance of blood type.

    My contributions to the code commented as LauraPG (create_family and free_family functions,
    starting at line 53).

    Link to the lab:
    https://cs50.harvard.edu/x/2023/labs/5/  */


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// LauraPG: Create a new individual with `generations`
person *create_family(int generations)
{
    // LauraPG: Allocate memory for new person
    person *p = malloc(sizeof(person));

    // If there are still generations left to create
    if (generations > 1)
    {
        // Set parent pointers for current person by recursively calling create_family
        p->parents[0] = create_family(generations - 1);
        p->parents[1] = create_family(generations - 1);

        // LauraPG: Randomly assign current person's alleles based on the alleles of their parents
        p->alleles[0] = p->parents[0]->alleles[rand() % 2];
        p->alleles[1] = p->parents[1]->alleles[rand() % 2];
    }

    // LauraPG: If there are no generations left to create (base case)
    else
    {
        // LauraPG: Set parent pointers to NULL
        p->parents[0] = NULL;
        p->parents[1] = NULL;

        // LauraPG: Randomly assign alleles
        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
    }

    // LauraPG: Return newly created person
    return p;
}

// LauraPG: Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // LauraPG: Handle base case
    if (p == NULL)
    {
        return;
    }

    // LauraPG: Free parents recursively
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // LauraPG: Free child
    free(p);
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Print parents of current generation
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
