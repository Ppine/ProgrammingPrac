#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


char **board;  // Game board
int player = 1;          // Player 1 or 2
int SIZE;

// Clear the screen based on the operating system
void clearScreen() 
{
    #ifdef _WIN32
        system("cls");    // Windows
    #else
        system("clear");  // Ubuntu, macOS
    #endif
}

// Initialize the board with '.'
void initBoard() 
{
    board = (char**)malloc(SIZE * sizeof(char*));
    for (int i = 0; i < SIZE; i++) 
    {
        board[i]= (char *)malloc(SIZE * sizeof(char));
        for (int j = 0; j < SIZE; j++) 
        {
            board[i][j] = '.';
        }
    }
}

void freeboard()
{
    for(int i=0; i<SIZE; i++)
    {
        free(board[i]);
    }
    free(board);
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
    if(*cnt == 0 && col != 'A' + SIZE / 2 && row!=SIZE/2+1) // first move
    {
        return 0; // first move has to be made to the center of the board
    }
    *x = row - 1; //2행
    *y = col - 'A'; //0열
    // printf("x = %d y=%d\n",*x,*y);
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

int checkFork(int x, int y, int *player)
{
    if(*player == 2) // white player has no restrictions
    {
        return 0;
    }
    else // player black
    {
        int tempcount;
        int checkblank;
        int dx[] = {1, 0, 1, 1};
        int dy[] = {0, 1, 1, -1};
        int forkCount3 = 0;  
        int forkCount4 = 0;

        for (int dir = 0; dir < 4; dir++) 
        {
            tempcount = 0;
            int count = 1; 
            int openEnds = 0;  
            checkblank=1;
            // Check in one direction
            for (int step = 1; step < SIZE; step++)
            {//e2
                checkblank++;
                int nx = x + step * dx[dir]; //x=2
                int ny = y + step * dy[dir]; //y=4
                if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE)
                {
                    // printf("one direction %d %d\n",nx,ny);
                    if (board[nx][ny] == 'O') 
                    {
                        count++;
                        checkblank++;
                        // printf("one count %d\n",count);
                    }
                    else if (board[nx][ny] == '.') 
                    {
                        openEnds++;
                        // printf("one openEnds %d\n",openEnds);
                        tempcount++;
                        // printf("detect blank\n");
                        // printf("tempcount = %d\n",tempcount);
                        if(tempcount > 1 || (tempcount == 1 && count <=3 && ((nx == 0 && x!=0) || (ny ==0 && y!=0) || (nx == 14 && nx!=14) || (ny == 14 && y!=14))))
                        {
                            openEnds--;
                            break;
                        }
                        // break;
                    } 
                    else 
                    {
                        break;
                    }
                }
            }
            tempcount = 0;
            // Check in the opposite direction
            for (int step = 1; step < SIZE; step++)
            {
                int nx = x - step * dx[dir];
                int ny = y - step * dy[dir];
                if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE)
                {
                    // printf("other direction %d %d\n",nx,ny);
                    if (board[nx][ny] == 'O')
                    {
                        count++;
                        // printf("other count %d\n",count);
                    }
                    else if (board[nx][ny] == '.')
                    {
                        openEnds++;
                        // printf("other openEnds %d\n",openEnds);
                        tempcount++;
                        // printf("DETECT BLANK\n");
                        // printf("tempcount = %d \n",tempcount);
                        if(tempcount > 1 || (tempcount == 1 && count <= 3 && ((nx == 0 && x!=0) || (ny ==0 && y!=0) || (nx == 14 && nx!=14) || (ny == 14 && y!=14))))
                        {
                            openEnds--;
                            break;
                        }
                        // break;
                    } 
                    else 
                    {
                        break;
                    }
                }
            }

            // open three
            if (count == 3 && openEnds == 2) 
            {
                forkCount3++;
                // printf("forkcount3++\n");
            }
            if(count == 4 && openEnds >=1)
            {
                forkCount4++;
                // printf("forkcount4++\n");
            }

            if(count > 5) // 6stones in a row
            {
                return 1;
            }
        }
        // open three -> forbidden move
        if (forkCount3 >= 2 || forkCount4 >= 2)
        {
            // printf("Player: %d, ForkCount3: %d, ForkCount4: %d. Forbidden move.\n", *player, forkCount3, forkCount4);
            return 1;
        }
        // printf("Player: %d, ForkCount3: %d, ForkCount4: %d. Move allwoed.\n", *player, forkCount3, forkCount4);
        return 0; 
    }
}

// Play the game
void playGame()
{
    char col;
    int row, x, y;
    clearScreen();  // Clear the screen
    int turn=0;

    printf("The first move has to be made to the center of the board.(%c%d)\n",'A' + SIZE / 2, SIZE / 2 + 1);

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
    printf("enter the board size(5~26)\n");
    scanf("%d",&SIZE);
    if(SIZE < 5 || SIZE > 26)
    {
        printf("invalid input size.\n");
        return 1;
    }
    initBoard();
    playGame();
    freeboard();
    return 0;  
}


// 마지막수 금수
// h8 h7 h10 i6 g8 i8 g6 i7 i9 f7 j7 e7 g7 00 33fork
// h8 a1 i8 a2 j8 a3 e8 b1 f8 c1 g8 00 6목
// h8 n1 a6 n2 b5 m1 c4 l1 e4 e6 e5 n3 e3 l2 e2 00 44fork
// h8 a1 i7 b1 j7 c1 j8 a2 j6 00 33fork
// h8 n1 b6 k4 b7 l9 b10 j8 b12 i3 b13 k5 b9 00
// h8 a1 j1 a2 m1 a3 n1 a4 m3 b1 n4 b2 o5 b3 k1 00

// 마지막수 가능
// h8 k1 b12 k2 b13 k3 d13 n1 d14 n2 c13 00

// 그러니까 지금 문제는 돌과 돌 사이가 떨어져있을 때 break로 인해서 그게 체크가 안 되고 넘어가는 상황인거임.
// 그래서 케이스3 에서 e2가 가능하다고 체크됨 왜냐? 만나서 그 뒤의 돌 숫자를 안 세거든.