#include <stdio.h>
#include <stdlib.h>

void votesRecord(int *Votes, int Voters);
void displayResults(int *Votes, int Candidates);

int main() {
    int Voters;
    const int Candidates = 3; 
    int *Votes;

    // Input number of voters
    printf("Please enter the number of voters: ");
    scanf("%d", &Voters);

    // Allocate memories using calloc since it is a contiguous allocation
    Votes = (int *)calloc(Candidates, sizeof(int));
    if (Votes == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    votesRecord(Votes, Voters);
    displayResults(Votes, Candidates);
    free(Votes);
    return 0;
}

void votesRecord(int *Votes, int Voters) {
    int vote;

    printf("Vote for candidates:\n");
    printf("1: Candidate 1\n");
    printf("2: Candidate 2\n");
    printf("3: Candidate 3\n");

    for (int i = 0; i < Voters; i++) { 
        printf("Pick your vote (1-3): ");
        scanf("%d", &vote);

        if (vote >= 1 && vote <= 3) {
            Votes[vote - 1]++;
        } else {
            printf("Invalid input! Please enter a number between 1 and 3 only.\n");
            i--;
        }
    }
}

void displayResults(int *Votes, int Candidates) {
    printf("\nElection Results:\n");
    printf("Candidate\tVotes\tHistogram\n");
    
    for (int i = 0; i < Candidates; i++) {
        printf("%d\t\t%d\t", i + 1, Votes[i]);

        for (int j = 0; j < Votes[i]; j++) {
            printf("#");
        }
        
        printf("\n");
    }
}