from collections import deque

def solution(rectangle, characterX, characterY, itemX, itemY):
    board = [[0] * 102 for _ in range(102)]

    # 좌표 2배 확대
    for x1, y1, x2, y2 in rectangle:
        x1, y1, x2, y2 = x1 * 2, y1 * 2, x2 * 2, y2 * 2

        for x in range(x1, x2 + 1):
            for y in range(y1, y2 + 1):
                if x1 < x < x2 and y1 < y < y2:
                    board[y][x] = 2   # 내부
                elif board[y][x] != 2:
                    board[y][x] = 1   # 테두리

    startX, startY = characterX * 2, characterY * 2
    endX, endY = itemX * 2, itemY * 2

    q = deque()
    q.append((startX, startY, 0))
    visited = [[False] * 102 for _ in range(102)]
    visited[startY][startX] = True

    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    while q:
        x, y, dist = q.popleft()

        if x == endX and y == endY:
            return dist // 2

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < 102 and 0 <= ny < 102:
                if not visited[ny][nx] and board[ny][nx] == 1:
                    visited[ny][nx] = True
                    q.append((nx, ny, dist + 1))
