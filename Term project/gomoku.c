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
int checkWin(int x, int y) {
    char stone = board[x][y];
    int dx[] = {1, 0, 1, 1};   // Horizontal, vertical, diagonal directions
    int dy[] = {0, 1, 1, -1};  // Horizontal, vertical, diagonal directions

    for (int dir = 0; dir < 4; dir++) {
        int count = 1;  // Include the current position

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

        if (count >= 5) {
            return 1;  // Victory
        }
    }

    return 0;  // Victory condition not met
}

// Play the game
void playGame() {
    char col;
    int row, x, y;
    clearScreen();  // Clear the screen
    int cnt=0;

    printf("The first move has to be made to the center of the board.(H8)\n");

    while (1) {
        printBoard();
        printf("Player %d's turn (enter column and row, e.g., A13): ", player);

        // Input processing
        scanf(" %c%d", &col, &row); // ignore blank
        col = toupper(col);  // Convert to uppercase

        // Convert input coordinates to board indices
        if (!convertInput(col, row, &x, &y,&cnt) || board[x][y] != '.') {
            clearScreen();  // Clear the screen
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Place the stone
        board[x][y] = (player == 1) ? 'O' : 'X';

        // Check for victory condition
        if (checkWin(x, y)) {
            clearScreen();
            printBoard();
            printf("Player %d wins!\n", player);
            break;
        }

        // Switch to the next player
        player = (player == 1) ? 2 : 1;
        clearScreen();  // Clear the screen
        cnt++;
    }
}

int main() {
    initBoard();
    playGame();
    return 0;
}
