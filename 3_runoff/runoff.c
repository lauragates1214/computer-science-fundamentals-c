/*
    PROGRAM :  Runoff
    AUTHOR  :  Laura Purcell-Gates
    EMAIL   :  <laurapurcellgates@gmail.com>

    CS50x 2023 Problem Set 3 Runoff

    Runoff is a program that simulates a runoff election.

    My contributions to the code commented as LauraPG (vote, tabulate, print_winner,
    find_min, is_tie and eliminate functions, starting at line 143).

    Link to the problem set:
    https://cs50.harvard.edu/x/2023/psets/3/runoff  */


#include <cs50.h>
#include <stdio.h>
#include <strings.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// LauraPG: Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // LauraPG: loop through candidate array
    for (int i = 0; i < candidate_count; i++)
    {
        // LauraPG: check whether name is in the array candidates[]
        if (strcasecmp(candidates[i].name, name) == 0)
        {
            // LauraPG: record preference - update global preferences array
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// LauraPG: Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // LauraPG: loop through voters array
    for (int i = 0; i < voter_count; i++)
    {
        // LauraPG: loop through candidates array
        for (int j = 0; j < candidate_count; j++)
        {
            // LauraPG: check if candidate already eliminated
            if (candidates[preferences[i][j]].eliminated == false)
            {
                // LauraPG: add 1 to their vote tally
                candidates[preferences[i][j]].votes += 1;
                break;
            }
        }
    }
    return;
}

// LauraPG: Print the winner of the election, if there is one
bool print_winner(void)
{
    // LauraPG: loop through candidate array
    for (int i = 0; i < candidate_count; i++)
    {
        // LauraPG: calculate whether any candidate has more than half the vote
        if (candidates[i].votes > voter_count / 2)
        {
            // LauraPG: print their name and return true
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// LauraPG: Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // LauraPG: create variable to store current min vote tally
    int min_votes = MAX_VOTERS;

    // LauraPG: loop through candidate array
    for (int i = 0; i < candidate_count; i++)
    {
        // LauraPG: only non-eliminated candidates
        if (!candidates[i].eliminated)
        {
            // LauraPG: reset min_votes every time find .votes value less than current value
            if (min_votes > candidates[i].votes)
            {
                min_votes = candidates[i].votes;
            }
        }
    }
    // LauraPG: return minimum votes
    return min_votes;
}

// LauraPG: Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // LauraPG: create variables to store non-eliminated candidates and candidates who have min votes (to compare)
    int candidates_rem = 0;
    int candidates_min_votes = 0;

    // LauraPG: loop through candidate array
    for (int i = 0; i < candidate_count; i++)
    {
        // LauraPG: count candidates remaining
        if (!candidates[i].eliminated)
        {
            candidates_rem += 1;

            // LauraPG: count candidates w min votes
            if (candidates[i].votes == min)
            {
                candidates_min_votes += 1;
            }
        }
    }
    // LauraPG: compare those variables; return true if match
    if (candidates_rem == candidates_min_votes)
    {
        return true;
    }
    return false;
}

// LauraPG: Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // LauraPG: loop through candidates array
    for (int i = 0; i < candidate_count; i++)
    {
        // LauraPG: only non-eliminated candidates
        if (!candidates[i].eliminated)
        {
            // LauraPG: check match with min
            if (candidates[i].votes == min)
            {
                // LauraPG: change eliminated bool to true
                candidates[i].eliminated = true;
            }
        }
    }
    return;
}