from collections import deque

def solution(maps):
    
    def bfs(x, y):
        mx, my = [0, 0, 1, -1], [1, -1, 0, 0]
        q = deque([(x, y)])
        food = int(maps[x][y])
        maps[x][y] = 'X'

        while q:
            x, y = q.popleft()

            for i in range(4):
                nx, ny = x + mx[i], y + my[i]

                if 0 <= nx < len(maps) and 0 <= ny < len(maps[0]) and maps[nx][ny] != 'X':
                    food += int(maps[nx][ny])
                    maps[nx][ny] = 'X'
                    q.append((nx, ny))

        return food

    answer = []
    
    for i in range(len(maps)):
        maps[i] = list(maps[i])
        
    for i in range(len(maps)):
        for j in range(len(maps[0])):
            if maps[i][j] != 'X':
                answer.append(bfs(i, j))
    
    return [-1] if answer == [] else sorted(answer)
