#include <stdio.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void printBoard()
{
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkWin()
{
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return 1;
    }

    // Columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return 1;
    }

    // Diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return 1;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return 1;

    return 0;
}

int checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] >= '1' && board[i][j] <= '9')
                return 0;
        }
    }

    return 1;
}

int main()
{
    int choice;
    char player = 'X';

    printf("===== TIC TAC TOE =====\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n");

    while (1)
    {
        printBoard();

        printf("Player %c, enter a position (1-9): ", player);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9)
        {
            printf("Invalid position! Try again.\n");
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            printf("That position is already taken! Try again.\n");
            continue;
        }

        board[row][col] = player;

        if (checkWin())
        {
            printBoard();
            printf("🎉 Player %c wins!\n", player);
            break;
        }

        if (checkDraw())
        {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}