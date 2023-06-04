/*
    PROGRAM :  Plurality
    AUTHOR  :  Laura Purcell-Gates
    EMAIl   :  <laurapurcellgates@gmail.com>

    CS50x 2023 Problem Set 3 Plurality

    Plurality is a program that simulates a plurality vote election.

    My contributions to the code commented as LauraPG (vote and print_winner functions).

    Link to the problem set:
    https://cs50.harvard.edu/x/2023/psets/3/plurality */
    

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // LauraPG: check for name match within array
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcasecmp(name, candidates[i].name) == 0)
        {
            // LauraPG: add a vote to that candidate's array position
            candidates[i].votes += 1;

            // LauraPG: return bool true
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // LauraPG: check highest number of votes using bubble search and return - use max_value function from practice problem
    // LauraPG: initialize variable to keep track of max value
    int max_value = candidates[0].votes;

    // LauraPG: loop through the array and reset this max value every time find a value that's larger
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < candidates[i + 1].votes)
        {
            max_value = candidates[i + 1].votes;
        }
    }

    // LauraPG: identify which candidates' vote tallies equal max_value
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == max_value)
        {
            printf("%s\n", candidates[j].name);
        }
    }
    return;
}