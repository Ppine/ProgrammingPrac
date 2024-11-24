자유전공학부 2024-14090 박영민

렌주 룰 정리

1. 시작은 흑돌 The player with the black stones begins the game.
2. 흑돌 첫 수는 무조건 중간 The first move has to be made to the center of the board.
3. 흑돌은 33 불가 (열린 3) Black player is not allowed to make the 3x3 fork.
4. 흑돌은 44도 불가 (열린 4) Black player is not allowed to make the 4x4 fork.
5. 흑돌은 6개 이상이 연결되는 것도 불가 Black player is not allowed to make an overline (6 or more stones in a row)


checkWin 함수에서 흑돌은 돌이 딱 5개가 맞아야 승리로 가능한 점을 이용하여 조건문을 추가했다.

checkFork 함수의 작동원리
1. 현재 수가 놓아지는 위치를 기반으로, 하 상 우 좌 우하 좌상 좌하 우상 순서대로 탐지한다.
2. 그 과정에서 공백이 1칸만 나오는 경우는 임시로 체크해두고 그 방향을 유지하여 추가적으로 탐지한다. 
이 과정은 O.OO0과 같이 공백이 존재하면서도 fork의 가능성이 있는 경우를 대비한다. (O는 기존에 존재하던 수, 0은 이번 차례에 놓은 수)
3. 탐지하는 과정에서 돌의 수와 열린 갯수를 저장하여 33,44,육목과 같은 경우를 판단한다.
4. 아무 문제가 없다면 넘어가고 문제가 생겼다면 사용자가 다시 놓을 수 있도록 한다.


추가 기능 -> SIZE 변경 기능.
게임을 시작할 때 SIZE를 선택할 수 있다.
기존 skeleton 코드에서 #define을 이용하여 정의되어있던 size와 전역변수로 지정된 board[SIZE][SIZE]를 변경했다.
board를 **로 지정해주고, size를 전역변수로 설정한 다음 main에서 실행되면 size를 입력받아, initboard 함수에서 메모리를 할당해주고, main이 끝날 때 free 한다.