for _ in range(10):
    tc = int(input())
    arr = [list(map(int, input().split())) for _ in range(100)]

    answer = 0

    for i in range(100):
        answer = max(answer, sum(arr[i]))
        answer = max(answer, sum(arr[j][i] for j in range(100)))

    answer = max(answer, sum(arr[i][i] for i in range(100)))
    answer = max(answer, sum(arr[i][99 - i] for i in range(100)))

    print(f"#{tc} {answer}")