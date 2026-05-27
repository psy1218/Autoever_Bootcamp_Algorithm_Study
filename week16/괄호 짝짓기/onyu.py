import sys
sys.stdin = open('input.txt', 'r')
input = sys.stdin.readline

for num in range(1, 11):
    n = int(input())
    arr = input().strip()
    check = []
    for i in arr:
        if len(check) == 0:
            check.append(i)
        elif (check[-1] == '[' and i == ']') or (check[-1] == '{' and i == '}') or (check[-1] == '<' and i == '>') or (check[-1] == '(' and  i==')'):
                check.pop()
        else:
            check.append(i)
    if len(check) == 0:
        print(f'#{num} 1')
    else:
        print(f'#{num} 0')