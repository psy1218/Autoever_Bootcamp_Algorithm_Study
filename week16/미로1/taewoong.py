
T = 10
 
# 상 하 좌 우
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]
 
def dfs(r, c):
 
    # 도착지 도달
    if maze[r][c] == 3:
        return 1
 
    # 방문 처리
    visited[r][c] = 1
 
    # 4방향 탐색
    for d in range(4):
 
        nr = r + dr[d]
        nc = c + dc[d]
 
        # 범위 안이고
        if 0 <= nr < 16 and 0 <= nc < 16:
 
            # 길 or 도착지 이면서 방문 안했으면
            if maze[nr][nc] != 1 and visited[nr][nc] == 0:
 
                if dfs(nr, nc):
                    return 1
 
    return 0
 
 
for tc in range(1, 11):
 
    input() 
 
    maze = [list(map(int, input())) for _ in range(16)]
 
    visited = [[0] * 16 for _ in range(16)]
 
    # 시작점 찾기
    for i in range(16):
        for j in range(16):
            if maze[i][j] == 2:
                sr, sc = i, j
 
    result = dfs(sr, sc)
 
    print(f"#{tc} {result}")
