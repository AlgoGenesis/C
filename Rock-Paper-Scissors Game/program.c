#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void playGame();
int getComputerChoice();
int getPlayerChoice();
void determineWinner(int playerChoice, int computerChoice);

int main()
{
    char playAgain;

    // Game loop
    do
    {
        playGame();

        // Ask if the player wants to play again
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}

// Function to play one round of Rock, Paper, Scissors
void playGame()
{
    int playerChoice = getPlayerChoice();
    int computerChoice = getComputerChoice();

    determineWinner(playerChoice, computerChoice);
}

// Function to get the computer's choice (random)
int getComputerChoice()
{
    srand(time(0));
    return rand() % 3; // Generates 0, 1, or 2 (Rock, Paper, or Scissors)
}

// Function to get the player's choice
int getPlayerChoice()
{
    int choice;

    printf("\nRock, Paper, Scissors Game!\n");
    printf("Enter your choice (0 = Rock, 1 = Paper, 2 = Scissors): ");
    scanf("%d", &choice);

    while (choice < 0 || choice > 2)
    {
        printf("Invalid choice! Please enter 0 (Rock), 1 (Paper), or 2 (Scissors): ");
        scanf("%d", &choice);
    }

    return choice;
}

// Function to determine the winner of the game
void determineWinner(int playerChoice, int computerChoice)
{
    // Mapping choices to strings for display
    char *choices[] = {"Rock", "Paper", "Scissors"};

    printf("You chose: %s\n", choices[playerChoice]);
    printf("Computer chose: %s\n", choices[computerChoice]);

    if (playerChoice == computerChoice)
    {
        printf("It's a draw!\n");
    }
    else if ((playerChoice == 0 && computerChoice == 2) || // Rock beats Scissors
             (playerChoice == 1 && computerChoice == 0) || // Paper beats Rock
             (playerChoice == 2 && computerChoice == 1))
    { // Scissors beats Paper
        printf("You win!\n");
    }
    else
    {
        printf("Computer wins!\n");
    }
}
