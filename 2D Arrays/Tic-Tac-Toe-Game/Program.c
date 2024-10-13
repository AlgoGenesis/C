#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function declarations
static void singlePlayerMode();
static void twoPlayerMode();
static void placeX(int);    // Place 'X' by Player 1
static void placeOComputer(); // Place 'O' by computer
static void placeO(int);     // Place 'O' by Player 2
int checkWinner();           // Check for a winner

static char board[9];        // 3x3 Tic-Tac-Toe board

int main()
{   
    srand((unsigned int)time(NULL));
    int playAgain = 0;

    do
    {
        int choice = 0;

        // Initialize the board
        for (int i = 0; i < 9; i++) board[i] = '*';

        // Display menu
        printf("***************************************\n");
        printf("************* TIC TAC TOE *************\n");
        printf("***************************************\n");
        printf("******* 1. YOU vs COMPUTER ************\n");
        printf("******* 2. YOU vs PLAYER **************\n");
        printf("******* 3. EXIT ***********************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
        case 1:
            singlePlayerMode();
            break;
        case 2:
            twoPlayerMode();
            break;
        default:
            printf("THANK YOU! EXITING...\n");
        }

        printf("Play again? Enter 1 for YES, 0 for NO: ");
        scanf("%d", &playAgain);

    } while (playAgain == 1);

    return 0;
}

void singlePlayerMode()
{
    int playerMove;
    int filledSlots = 0;

    for (int i = 0; i < 9; i++) printf("%c ", board[i % 3 == 0 ? i : i % 3 == 0]);

    for (int moveCount = 1; moveCount <= 9; moveCount++)
    {
        printf("Your move (1-9): ");
        scanf("%d", &playerMove);

        placeX(playerMove);

        if (filledSlots < 4)
        {
            placeOComputer();
        }

        for (int i = 0; i < 9; i++) printf("%c ", board[i % 3 == 0 ? i : i % 3 == 0]);
        
        filledSlots++;
        int result = checkWinner();

        if (result == -1)
        {
            printf("YOU WIN!\n");
            break;
        }
        else if (result == -2)
        {
            printf("COMPUTER WINS!\n");
            break;
        }

        if (filledSlots == 4)
        {
            printf("\nDRAW\n");
            break;
        }
    }
}

void twoPlayerMode()
{
    int player1Move, player2Move;
    int filledSlots = 0;

    for (int i = 0; i < 9; i++) printf("%c ", board[i % 3 == 0 ? i : i % 3 == 0]);

    for (int moveCount = 1; moveCount <= 9; moveCount++)
    {
        printf("Player 1 (X), enter your move: ");
        scanf("%d", &player1Move);
        placeX(player1Move);

        if (filledSlots < 4)
        {
            printf("Player 2 (O), enter your move: ");
            scanf("%d", &player2Move);
            placeO(player2Move);
        }

        for (int i = 0; i < 9; i++) printf("%c ", board[i % 3 == 0 ? i : i % 3 == 0]);
        
        filledSlots++;
        int result = checkWinner();

        if (result == -1)
        {
            printf("Player 1 WINS!\n");
            break;
        }
        else if (result == -2)
        {
            printf("Player 2 WINS!\n");
            break;
        }

        if (filledSlots == 4)
        {
            printf("\nDRAW\n");
            break;
        }
    }
}

void placeX(int position)
{
    while (position < 1 || position > 9 || board[position - 1] != '*')
    {
        printf("Invalid move. Enter again: ");
        scanf("%d", &position);
    }
    board[position - 1] = 'X';
}

void placeOComputer()
{
    int position = rand() % 9;
    while (board[position] != '*')
    {
        position = rand() % 9;
    }
    board[position] = 'O';
    printf("\nComputer placed 'O' at position %d\n", position + 1);
}

void placeO(int position)
{
    while (position < 1 || position > 9 || board[position - 1] != '*')
    {
        printf("Invalid move. Enter again: ");
        scanf("%d", &position);
    }
    board[position - 1] = 'O';
}

int checkWinner()
{
    // Check rows, columns, and diagonals
    if (board[0] == board[1] && board[1] == board[2]) return (board[0] == 'X') ? -1 : -2;
    if (board[3] == board[4] && board[4] == board[5]) return (board[3] == 'X') ? -1 : -2;
    if (board[6] == board[7] && board[7] == board[8]) return (board[6] == 'X') ? -1 : -2;
    if (board[0] == board[3] && board[3] == board[6]) return (board[0] == 'X') ? -1 : -2;
    if (board[1] == board[4] && board[4] == board[7]) return (board[1] == 'X') ? -1 : -2;
    if (board[2] == board[5] && board[5] == board[8]) return (board[2] == 'X') ? -1 : -2;
    if (board[0] == board[4] && board[4] == board[8]) return (board[0] == 'X') ? -1 : -2;
    if (board[2] == board[4] && board[4] == board[6]) return (board[2] == 'X') ? -1 : -2;
    
    return 0;
}