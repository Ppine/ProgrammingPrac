#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 15

char board[SIZE][SIZE];  // Game board
int player = 1;          // Player 1 or 2

// Clear the screen based on the operating system
void clearScreen() 
{
    #ifdef _WIN32
        system("cls");    // Windows
    #else
        // system("clear");  // Ubuntu, macOS
    #endif
}

// Initialize the board with '.'
void initBoard() 
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            board[i][j] = '.';
        }
    }
}

// Print the game board
void printBoard() 
{
    printf("   ");
    for (int i = 0; i < SIZE; i++) 
    {
        printf("%c ", 'A' + i);  // Column labels
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) 
    {
        printf("%2d ", i + 1);  // Row labels
        for (int j = 0; j < SIZE; j++) 
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Convert input like 'A13' into board indices
int convertInput(char col, int row, int *x, int *y, int *cnt) 
{
    if (col < 'A' || col > 'O' || row < 1 || row > SIZE) 
    {
        return 0;  // Invalid input
    }
    if(*cnt == 0 && col != 'H' && row!=8) // first move
    {
        return 0; // first move has to be made to the center of the board
    }
    *x = row - 1; //2행
    *y = col - 'A'; //0열
    printf("x = %d y=%d\n",*x,*y);
    return 1;
}

// Check if there are 5 stones in a row
int checkWin(int x, int y, int *player) 
{
    char stone = board[x][y];
    int dx[] = {1, 0, 1, 1};   // Horizontal, vertical, diagonal directions
    int dy[] = {0, 1, 1, -1};  // Horizontal, vertical, diagonal directions

    for (int dir = 0; dir < 4; dir++) 
    {
        int count = 1;  

        // Check in one direction
        for (int step = 1; step < 5; step++) 
        {
            int nx = x + step * dx[dir];
            int ny = y + step * dy[dir];
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == stone) 
            {
                count++;
            } 
            else 
            {
                break;
            }
        }

        // Check in the opposite direction
        for (int step = 1; step < 5; step++) 
        {
            int nx = x - step * dx[dir];
            int ny = y - step * dy[dir];
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == stone) 
            {
                count++;
            } 
            else 
            {
                break;
            }
        }

        if (count >= 5 && *player == 2) 
        {
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

int checkFork(int x, int y, int *player) {
    if (*player == 2) // 백돌은 제한 없음
        return 0;

    int dx[] = {1, 0, 1, 1};
    int dy[] = {0, 1, 1, -1};
    int forkCount3 = 0, forkCount4 = 0;

    for (int dir = 0; dir < 4; dir++) {
        int count = 1, openEnds = 0;
        int forwardCount = 0, backwardCount = 0; // 정방향, 역방향 연속 돌 개수
        int forwardOpen = 0, backwardOpen = 0;  // 정방향, 역방향 열린 끝 개수

        // 정방향 탐색
        for (int step = 1; step < SIZE; step++) {
            int nx = x + step * dx[dir];
            int ny = y + step * dy[dir];
            if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE)
                break;
            if (board[nx][ny] == 'O') {
                forwardCount++;
            } else if (board[nx][ny] == '.') {
                forwardOpen++;
                break;
            } else {
                break;
            }
        }

        // 역방향 탐색
        for (int step = 1; step < SIZE; step++) {
            int nx = x - step * dx[dir];
            int ny = y - step * dy[dir];
            if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE)
                break;
            if (board[nx][ny] == 'O') {
                backwardCount++;
            } else if (board[nx][ny] == '.') {
                backwardOpen++;
                break;
            } else {
                break;
            }
        }

        // 총 연속 돌 개수 및 열린 끝 개수 계산
        count = 1 + forwardCount + backwardCount;
        openEnds = forwardOpen + backwardOpen;

        // 금수 조건 확인
        if (count == 3 && openEnds == 2) {
            forkCount3++;
        }
        if (count == 4 && openEnds >= 1) {
            forkCount4++;
        }
        if (count > 5) { // 6목 이상은 금수
            return 1;
        }
    }

    // 열린 삼삼 또는 사사 조건
    if (forkCount3 >= 2 || forkCount4 >= 2) {
        printf("Player: %d, ForkCount3: %d, ForkCount4: %d. Forbidden move.\n", *player, forkCount3, forkCount4);
        return 1;
    }

    printf("Player: %d, ForkCount3: %d, ForkCount4: %d. Move allowed.\n", *player, forkCount3, forkCount4);
    return 0; // 금수 아님
}

// Play the game
void playGame()
{
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
        if (!convertInput(col, row, &x, &y,&turn) || board[x][y] != '.') // check duplication or out of board
        {
            
            clearScreen();
            printf("Invalid move. Try again.\n");
            continue;
        }
         // Place the stone
        board[x][y] = (player == 1) ? 'O' : 'X';
        if(checkFork(x, y, &player))
        {
            // Return the stone
            board[x][y] = '.';
            clearScreen();
            printf("Invalid move(fork). Try again\n");
            continue;
        }

        // // Place the stone
        // board[x][y] = (player == 1) ? 'O' : 'X';

        // Check for victory condition
        if (checkWin(x, y, &player)) 
        {
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

int main() 
{
    initBoard();
    playGame();
    return 0;  
}


// 마지막수 금수
// h8 h7 h10 i6 g8 i8 g6 i7 i9 f7 j7 e7 g7 00 33fork
// h8 a1 i8 a2 j8 a3 e8 b1 f8 c1 g8 00 6목
// h8 n1 a6 n2 b5 m1 c4 l1 e4 e6 e5 n3 e3 l2 e2 00 44fork
// h8 a1 i7 b1 j7 c1 j8 a2 j6 00 33fork
// h8 n1 b6 k4 b7 l9 b10 j8 b12 i3 b13 k5 b9 00
// h8 a1 j1 a2 m1 a3 n1 a4 m3 b1 n4 b2 o5 b3 k1 00
// h8 a1 h13 a2 f13 a3 j13 a4 l13 b1 i13

// 마지막수 가능
// h8 k1 b12 k2 b13 k3 d13 n1 d14 n2 c13 00

// 그러니까 지금 문제는 돌과 돌 사이가 떨어져있을 때 break로 인해서 그게 체크가 안 되고 넘어가는 상황인거임.
// 그래서 케이스3 에서 e2가 가능하다고 체크됨 왜냐? 만나서 그 뒤의 돌 숫자를 안 세거든.

// 탐색 방향 하 상 우 좌 우하 좌상 좌하 우상