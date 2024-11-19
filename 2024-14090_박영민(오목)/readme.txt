자유전공학부 2024-14090 박영민

렌주 룰 정리

1. 시작은 흑돌 The player with the black stones begins the game.
2. 흑돌 첫 수는 무조건 중간 The first move has to be made to the center of the board.
3. 흑돌은 33 불가 (열린 3) Black player is not allowed to make the 3x3 fork.
4. 흑돌은 44도 불가 (열린 4) Black player is not allowed to make the 4x4 fork.
5. 흑돌은 6개 이상이 연결되는 것도 불가 Black player is not allowed to make an overline (6 or more stones in a row)


checkWin 함수에서 흑돌은 돌이 딱 5개가 맞아야 승리로 가능한 점을 이용하여 조건문을 추가했다.

checkFork 함수를 만들어서 렌주룰에서 위배되는 open3, open4를 체크하였다.
O인 경우에 돌의 갯수를 count++을 이용하여 추가하고, .인 경우에 openEnds를 추가한다.
즉 열려있는 상태를 체크한다.

이 상태에서 fork의 조건을 만족한다면 다시 수를 놓을 수 있도록 한다.