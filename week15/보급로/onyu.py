import heapq

T = int(input())

for tc in range(1, T + 1):
    N = int(input())
    arr = [list(map(int, input().strip())) for _ in range(N)]

    INF = 10**9
    dist = [[INF] * N for _ in range(N)]
    dist[0][0] = 0

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    pq = []
    heapq.heappush(pq, (0, 0, 0))  # 비용, x, y

    while pq:
        cost, x, y = heapq.heappop(pq)

        if cost > dist[x][y]:
            continue

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < N and 0 <= ny < N:
                new_cost = cost + arr[nx][ny]

                if new_cost < dist[nx][ny]:
                    dist[nx][ny] = new_cost
                    heapq.heappush(pq, (new_cost, nx, ny))

    print(f"#{tc} {dist[N - 1][N - 1]}")