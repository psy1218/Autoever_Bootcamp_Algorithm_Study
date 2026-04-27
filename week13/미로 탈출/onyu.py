from collections import deque

def solution(maps):
    answer = 0
    
    n = len(maps)
    m = len(maps[0])
    
    for i in range(n):
        for j in range(m):
            if maps[i][j] == 'S':
                start = (j, i)
            elif maps[i][j] == 'L':
                lever = (j, i)
            elif maps[i][j] == 'E':
                end = (j, i)

    def bfs(start, end):
        visited = [[0]*m for _ in range(n)]
        visited[start[1]][start[0]] = 1
        dq = deque()
        dq.append(start)
        
        dx = [0, 0, -1, 1]
        dy = [-1, 1, 0, 0]
        
        while dq:
            x, y = dq.popleft()
            
            if end[0] == x and end[1] == y:
                return visited[end[1]][end[0]] - 1

            for d in range(4):
                nx, ny = x+dx[d], y+dy[d]
                if 0<=nx<m and 0<=ny<n and visited[ny][nx] == 0 and maps[ny][nx] != 'X':
                    visited[ny][nx] = visited[y][x] + 1
                    dq.append((nx, ny))
        return -1

    
    result = bfs(start, lever)
    if result == -1:
        return result
    answer += result
    result = bfs(lever, end)
    if result == -1:
        return result
    answer += result

    return answer