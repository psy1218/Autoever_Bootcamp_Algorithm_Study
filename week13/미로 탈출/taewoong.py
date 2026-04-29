from collections import deque

def bfs(start, end, maps):
    dx = [1, 0, 0, -1]
    dy = [0, 1, -1, 0]

    n = len(maps)#세로
    m = len(maps[0])#가로
    visited = [[False] * m for _ in range(n)]
    queue = deque()
    check = False

    for i in range(n):
        for j in range(m):
            if maps[i][j] == start:
                queue.append((i, j, 0))
                visited[i][j] = True
                check = True
                break
        if check: #시작위치찾앗씀
            break

    while queue:
        y, x, cost = queue.popleft()

        if maps[y][x] == end:#목표지점찾움
            return cost

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < n and 0 <= nx < m and maps[ny][nx] != 'X':
                if not visited[ny][nx]:
                    queue.append((ny, nx, cost + 1))
                    visited[ny][nx] = True

    return -1


def solution(maps):
    p = bfs('S', 'L', maps)#출발점->레버
    p2 = bfs('L', 'E', maps)#레버->나가기

    if p != -1 and p2 != -1:
        return p + p2

    return -1



