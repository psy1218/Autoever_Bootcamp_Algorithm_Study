
T = int(input())

def dfs(row):
    global count

    # N개의 퀸을 다 놓은 경우
    if row == N:
        count += 1
        return

    # 현재 행의 모든 열 탐색
    for col in range(N):

        # 현재 위치에 퀸 놓기
        board[row] = col

        # 놓을 수 있는 위치인지 확인
        if check(row):
            dfs(row + 1)


def check(row):

    # 이전 행들과 비교
    for i in range(row):

        # 같은 열인지 확인
        if board[row] == board[i]:
            return False

        # 대각선인지 확인
        if abs(board[row] - board[i]) == abs(row - i):
            return False

    return True


for tc in range(1, T + 1):

    N = int(input())

    # board[i] = i행의 퀸 열 위치
    board = [0] * N

    count = 0

    dfs(0)

    print(f"#{tc} {count}")
