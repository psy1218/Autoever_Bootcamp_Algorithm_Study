import sys
sys.stdin = open('input.txt', 'r')
input = sys.stdin.readline

for _ in range(10):
    t = int(input())
    arr = [input().strip() for _ in range(100)]

    # 세로줄도 문자열로 만들어두기
    cols = []
    for x in range(100):
        col = ''
        for y in range(100):
            col += arr[y][x]
        cols.append(col)

    answer = 0

    # 길이를 100부터 줄여가며 확인
    for length in range(100, 0, -1):
        found = False

        # 가로 확인
        for y in range(100):
            for start in range(100 - length + 1):
                word = arr[y][start:start + length]

                if word == word[::-1]:
                    answer = length
                    found = True
                    break

            if found:
                break

        # 세로 확인
        if not found:
            for x in range(100):
                for start in range(100 - length + 1):
                    word = cols[x][start:start + length]

                    if word == word[::-1]:
                        answer = length
                        found = True
                        break

                if found:
                    break

        # 가장 긴 길이부터 찾기 때문에 발견하면 종료
        if found:
            break

    print(f'#{t} {answer}')