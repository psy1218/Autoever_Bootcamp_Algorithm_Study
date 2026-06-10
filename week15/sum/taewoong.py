for tc in range(1,11):
    num = int(input())
    data = [list(map(int, input().split())) for i in range(100)]
    max = 0
    
#행
    for y in range(100):
        sum = 0
        for x in range(100):
            sum += data[y][x]
        if sum > max:
            max = sum
            
#열
    for x in range(100):
        sum = 0
        for y in range(100):
            sum += data[y][x]
        if sum > max:
            max = sum
            
#대각선1
    sum = 0
    for i in range(100):
        sum += data[i][i]
        if sum > max:
            max = sum
            
#대각선2
    sum = 0
    for i in range(100):
        sum += data[i][99-i]
        if sum > max:
            max = sum
            
    print(f"#{tc} {max}"
출처: https://datdaradanadat.tistory.com/9 [닿망징창 여정:티스토리]
