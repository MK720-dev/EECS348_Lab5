#include <stdio.h>

// Function to print combinations of scoring plays for a given score
void printCombinations(int score) {
    printf("Possible combinations for score %d:\n", score);

    // Check for each possible combination
    for (int TD2PC = 0; TD2PC * 8 <= score; TD2PC +=1){
        for (int TD1PFG = 0; TD1PFG * 7 <= score; TD1PFG += 1){
            for (int touchdowns = 0; touchdowns * 6 <= score; touchdowns++) {
                for (int fieldGoals = 0; touchdowns * 6 + fieldGoals * 3 <= score; fieldGoals++) {
                    for (int safeties = 0; touchdowns * 6 + fieldGoals * 3 + safeties * 2 <= score; safeties++) {
                        int totalScore = 8*TD2PC + 7*TD1PFG + touchdowns * 6 + fieldGoals * 3 + safeties * 2;

                        // Check if total score matches the target score
                        if (totalScore == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TD2PC, TD1PFG, touchdowns, fieldGoals, safeties);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    // Prompt user for a score until a value less than or equal to 1 is entered
    while (1) {
        printf("Enter the score (Enter 0 or negative to quit): ");
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        // Print combinations for the entered score
        printCombinations(score);
    }

    printf("Program terminated.\n");

    return 0;
}