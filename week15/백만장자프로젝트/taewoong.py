
T = int(input())

for tc in range(1, T + 1):
    N = int(input())
    price = list(map(int, input().split()))
    revenue = 0

    max_val = price[-1]
    for i in range(N - 1, -1, -1):
        if price[i] >= max_val:
            max_val = price[i]
        revenue += max_val - price[i]

    print("#{} {}".format(tc, revenue))
