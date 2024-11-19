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
    if (*cnt == 0 && !(col == 'H' && row == 8)) // black first move center
    { 
        return 0;
    }
    *x = row - 1;
    *y = col - 'A';
    return 1;
}

// Check if there are exactly 5 stones in a row
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

        if (count == 5) {  // Exact 5 stones
            return 1;
        }
    }

    return 0;  // Victory condition not met
}

// Check forbidden move (삼삼 or 사사)
int checkForbidden(int x, int y) {
    int dx[] = {1, 0, 1, 1};
    int dy[] = {0, 1, 1, -1};
    int threeCount = 0;  // 삼삼
    int fourCount = 0;   // 사사

    for (int dir = 0; dir < 4; dir++) {
        int count = 1;
        int openEnds = 0;

        // Positive direction
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

        // Negative direction
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

        if (count == 3 && openEnds == 2) {
            threeCount++;
        }
        if (count == 4 && openEnds >= 1) {
            fourCount++;
        }
    }

    if (threeCount >= 2 || fourCount >= 2) {
        return 1;  // Forbidden move
    }
    return 0;
}

// Play the game
void playGame() {
    char col;
    int row, x, y;
    clearScreen();  // Clear the screen
    int cnt = 0;

    printf("The first move must be at the center of the board (H8).\n");

    while (1) {
        printBoard();
        printf("Player %d's turn (enter column and row, e.g., A13): ", player);

        // Input processing
        scanf(" %c%d", &col, &row);
        col = toupper(col);

        // Convert input coordinates to board indices
        if (!convertInput(col, row, &x, &y, &cnt) || board[x][y] != '.') {
            clearScreen();
            printf("Invalid move. Try again.\n");
            continue;
        }

        if (player == 1 && checkForbidden(x, y)) {
            clearScreen();
            printf("Forbidden move (삼삼 or 사사). Try again.\n");
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
        clearScreen();
        cnt++;
    }
}

int main() {
    initBoard();
    playGame();
    return 0;
}
