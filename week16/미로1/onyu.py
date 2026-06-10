import sys
sys.stdin = open('input.txt', 'r')
input = sys.stdin.readline
from collections import deque

for t in range(1, 11):
    n = int(input())
    maze = [input().strip() for _ in range(16)]

    dq = deque()
    dq.append((1, 1))

    visited = [[False] * 16 for _ in range(16)]
    visited[1][1] = True

    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]

    check = 0

    while dq:
        x, y = dq.popleft()

        if maze[y][x] == '3':
            check = 1
            break

        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]

            if 0 <= nx < 16 and 0 <= ny < 16:
                if not visited[ny][nx] and maze[ny][nx] in ('0', '3'):
                    dq.append((nx, ny))
                    visited[ny][nx] = True

    print(f'#{n} {check}')