#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char determineWinner(char userChoice, char computerChoice)
{
  if (userChoice == computerChoice)
  {
    return 'D'; // Draw
  }
  else if ((userChoice == 's' && computerChoice == 'p') ||
           (userChoice == 'p' && computerChoice == 'r') ||
           (userChoice == 'r' && computerChoice == 's'))
  {
    return 'C'; // Computer wins
  }
  else
  {
    return 'U'; // User wins
  }
}

void playGame(int rounds, int *userWins, int *computerWins)
{
  if (rounds == 0)
  {
    if (*userWins > *computerWins)
    {
      printf("User wins the game with %d wins!\n", *userWins);
    }
    else if (*computerWins > *userWins)
    {
      printf("Computer wins the game with %d wins!\n", *computerWins);
    }
    else
    {
      printf("It's a tie game!\n");
    }
    return;
  }

  char userChoice;
  printf("Enter your choice (r for rock, p for paper, s for scissors): ");
  scanf(" %c", &userChoice);

  srand(time(0));
  int randomChoice = rand() % 3;
  char computerChoice = (randomChoice == 0) ? 'r' : (randomChoice == 1) ? 'p'
                                                                        : 's';

  printf("Computer chose: %c\n", computerChoice);

  char roundResult = determineWinner(userChoice, computerChoice);
  if (roundResult == 'U')
  {
    printf("User wins this round.\n");
    (*userWins)++;
  }
  else if (roundResult == 'C')
  {
    printf("Computer wins this round.\n");
    (*computerWins)++;
  }
  else
  {
    printf("It's a draw this round.\n");
  }

  playGame(rounds - 1, userWins, computerWins);
}

int main()
{
  int rounds;
  printf("Welcome to Stone Paper Scissors Game!\n");
  printf("Enter the number of rounds: ");
  scanf("%d", &rounds);

  int userWins = 0, computerWins = 0;

  playGame(rounds, &userWins, &computerWins);

  return 0;
}
