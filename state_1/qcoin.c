#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEADS 0
#define TAILS 1
#define TOTAL_GAMES 1000

/* Function to simulate a random coin flip
 * Returns: HEADS (0) or TAILS (1)
 */
int flip_coin() {
    return rand() % 2;
}

/* Function to play one quantum coin game round
 * Parameters:
 *   userFlip - user's choice to flip (1) or not flip (0)
 * Returns: final state of coin (HEADS or TAILS)
 */
int play_quantum_round(int userFlip) {
    int coin_state = HEADS;
    
    // First quantum operation
    if(flip_coin()) coin_state = !coin_state;
    
    // User's flip
    if(userFlip) coin_state = !coin_state;
    
    // Second quantum operation
    if(flip_coin()) coin_state = !coin_state;
        
    return coin_state;
}

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    int user_score = 0;
    int computer_score = 0;
        
    // Play multiple rounds
    for(int round = 0; round < TOTAL_GAMES; round++) {
        int user_choice = flip_coin();
        int result = play_quantum_round(user_choice);
        
        if(result == HEADS) computer_score++;
        else user_score++;
    }
    
    // Display results
    printf("\game results:\n");
    printf("user score: %d\n", user_score);
    printf("computer score: %d\n", computer_score);
    printf("win rate: user %.2f%% - computer %.2f%%\n", 
           (float)user_score/TOTAL_GAMES * 100,
           (float)computer_score/TOTAL_GAMES * 100);
    
    return 0;
}

/*
sample: 
game results:
user score: 488
computer score: 512
win rate: user 48.80% - computer 51.20%

The randomness comes from:
    - First quantum operation (random flip)
    - User's choice (random flip)
    - Second quantum operation (random flip)
*/