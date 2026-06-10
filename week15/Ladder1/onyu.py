# SWEA 1210. Ladder1

for _ in range(10):
    tc = int(input())
    ladder = [list(map(int, input().split())) for _ in range(100)]

    # 도착점 2의 위치에서 위로 거슬러 올라가기
    x = 99
    y = ladder[99].index(2)

    while x > 0:
        # 왼쪽으로 갈 수 있으면 끝까지 이동
        if y > 0 and ladder[x][y - 1] == 1:
            while y > 0 and ladder[x][y - 1] == 1:
                y -= 1

        # 오른쪽으로 갈 수 있으면 끝까지 이동
        elif y < 99 and ladder[x][y + 1] == 1:
            while y < 99 and ladder[x][y + 1] == 1:
                y += 1

        # 위로 이동
        x -= 1

    print(f"#{tc} {y}")