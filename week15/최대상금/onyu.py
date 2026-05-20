# SWEA 1244. 최대 상금

T = int(input())

for tc in range(1, T + 1):
    numbers, change = input().split()
    change = int(change)

    arr = list(numbers)
    n = len(arr)

    visited = set()
    answer = 0

    def dfs(cnt):
        global answer

        current = ''.join(arr)

        # 같은 숫자 상태 + 같은 교환 횟수는 다시 볼 필요 없음
        if (current, cnt) in visited:
            return
        visited.add((current, cnt))

        if cnt == change:
            answer = max(answer, int(current))
            return

        for i in range(n - 1):
            for j in range(i + 1, n):
                arr[i], arr[j] = arr[j], arr[i]
                dfs(cnt + 1)
                arr[i], arr[j] = arr[j], arr[i]

    dfs(0)

    print(f"#{tc} {answer}")