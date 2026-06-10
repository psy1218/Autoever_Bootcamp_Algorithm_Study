# SWEA 1859. 백만 장자 프로젝트

T = int(input())

for tc in range(1, T + 1):
    N = int(input())
    prices = list(map(int, input().split()))

    max_price = 0
    profit = 0

    # 뒤에서부터 확인
    for i in range(N - 1, -1, -1):
        if prices[i] > max_price:
            max_price = prices[i]
        else:
            profit += max_price - prices[i]

    print(f"#{tc} {profit}")