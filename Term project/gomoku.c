#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 15

char board[SIZE][SIZE];  // Game board
int player = 1;          // Player 1 or 2

// Clear the screen based on the operating system
void clearScreen() {
#ifdef _WIN32
    system("cls");    // Windows
#else
    system("clear");  // Ubuntu, macOS
#endif
}

// Initialize the board with '.'
void initBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

// Print the game board
void printBoard() {
    printf("   ");
    for (int i = 0; i < SIZE; i++) {
        printf("%c ", 'A' + i);  // Column labels
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%2d ", i + 1);  // Row labels
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Convert input like 'A13' into board indices
int convertInput(char col, int row, int *x, int *y, int *cnt) {
    if (col < 'A' || col > 'O' || row < 1 || row > SIZE) {
        return 0;  // Invalid input
    }
    if(*cnt == 0 && col != 'H' && row!=8) // first move
    {
        return 0; // first move has to be made to the center of the board
    }
    *x = row - 1;
    *y = col - 'A';
    return 1;
}

// Check if there are 5 stones in a row
int checkWin(int x, int y, int *player) {
    char stone = board[x][y];
    int dx[] = {1, 0, 1, 1};   // Horizontal, vertical, diagonal directions
    int dy[] = {0, 1, 1, -1};  // Horizontal, vertical, diagonal directions

    for (int dir = 0; dir < 4; dir++) {
        int count = 1;  

        // Check in one direction
        for (int step = 1; step < 5; step++) {
            int nx = x + step * dx[dir];
            int ny = y + step * dy[dir];
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == stone) {
                count++;
            } else {
                break;
            }
        }

        // Check in the opposite direction
        for (int step = 1; step < 5; step++) {
            int nx = x - step * dx[dir];
            int ny = y - step * dy[dir];
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == stone) {
                count++;
            } else {
                break;
            }
        }

        if (count >= 5 && *player == 2) {
            return 1;  // Victory (white)
        }
        else if (count == 5 && *player ==1)
        {
            return 1; // Victory (black)
        }
        else if(count > 5 && *player ==1)
        {
            return 0; // black can not make 6 in a row
        }
    }

    return 0;  // Victory condition not met
}

int checkFork(int x, int y, int *player)
{
    if(*player == 2) // white player has no restrictions
    {
        return 0;
    }
    else // player black
    {
        int dx[] = {1, 0, 1, 1};
        int dy[] = {0, 1, 1, -1};
        int forkCount3 = 0;  
        int forkCount4 = 0;

        for (int dir = 0; dir < 4; dir++) {
            int count = 1; 
            int openEnds = 0;  

            // Check in one direction
            for (int step = 1; step < 5; step++) {
                int nx = x + step * dx[dir];
                int ny = y + step * dy[dir];
                if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
                    if (board[nx][ny] == 'O') {
                        count++;
                    } else if (board[nx][ny] == '.') {
                        openEnds++;
                        break;
                    } else {
                        break;
                    }
                }
            }

            // Check in the opposite direction
            for (int step = 1; step < 5; step++) {
                int nx = x - step * dx[dir];
                int ny = y - step * dy[dir];
                if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
                    if (board[nx][ny] == 'O') {
                        count++;
                    } else if (board[nx][ny] == '.') {
                        openEnds++;
                        break;
                    } else {
                        break;
                    }
                }
            }

            // open three
            if (count == 3 && openEnds == 2) 
            {
                forkCount3++;
            }
            if(count == 4 && openEnds >=1)
            {
                forkCount4++;
            }

            // open three -> forbidden move
            if (forkCount3 >= 2 || forkCount4 >= 2) {
                return 1;
            }
        }

        return 0; 
    }
}

// Play the game
void playGame() {
    char col;
    int row, x, y;
    clearScreen();  // Clear the screen
    int turn=0;

    printf("The first move has to be made to the center of the board.(H8)\n");

    while (1) {
        printBoard();
        printf("Player %d's turn (enter column and row, e.g., A13): ", player);

        // Input processing
        scanf(" %c%d", &col, &row); // ignore blank
        col = toupper(col);  // Convert to uppercase

        // Convert input coordinates to board indices
        if (!convertInput(col, row, &x, &y,&turn) || board[x][y] != '.') {
            clearScreen();  // Clear the screen
            printf("Invalid move. Try again.\n");
            continue;
        }
        if(checkFork(x, y, &player))
        {
            clearScreen();
            printf("Invalid move(fork). Try again\n");
            continue;
        }

        // Place the stone
        board[x][y] = (player == 1) ? 'O' : 'X';

        // Check for victory condition
        if (checkWin(x, y, &player)) {
            clearScreen();
            printBoard();
            printf("Player %d wins!\n", player);
            break;
        }

        // Switch to the next player
        player = (player == 1) ? 2 : 1;
        clearScreen();  // Clear the screen
        turn++;
    }
}

int main() {
    initBoard();
    playGame();
    return 0;  
}
