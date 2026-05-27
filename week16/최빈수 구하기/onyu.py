import sys
sys.stdin = open('input.txt', 'r')
input = sys.stdin.readline
from collections import defaultdict

T = int(input())

for t in range(1, T+1):
    n = int(input())
    arr = list(map(int, input().split()))

    check = defaultdict(int)
    answer = 0
    answer_count = 0
    for num in arr:
        check[num] += 1
        if answer_count < check[num]:
            answer_count = check[num]
            answer = num
    print(f'#{t} {answer}')