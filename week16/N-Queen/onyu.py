import sys
sys.stdin = open('input.txt', 'r')
input = sys.stdin.readline

T = int(input())

for tc in range(1, T + 1):
    N = int(input())

    col = [False] * N
    diag1 = [False] * (2 * N)
    diag2 = [False] * (2 * N)

    def backtracking(row):
        # N개의 행에 모두 Queen을 놓았다면 경우의 수 1개
        if row == N:
            return 1

        count = 0

        for c in range(N):
            # 같은 열에 Queen이 있으면 불가능
            if col[c]:
                continue

            # 왼쪽 아래 ↔ 오른쪽 위 대각선
            if diag1[row + c]:
                continue

            # 왼쪽 위 ↔ 오른쪽 아래 대각선
            if diag2[row - c + N]:
                continue

            # Queen 놓기
            col[c] = True
            diag1[row + c] = True
            diag2[row - c + N] = True

            # 다음 행으로 이동
            count += backtracking(row + 1)

            # Queen 빼기
            col[c] = False
            diag1[row + c] = False
            diag2[row - c + N] = False

        return count

    answer = backtracking(0)

    print(f'#{tc} {answer}')