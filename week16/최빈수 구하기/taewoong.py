
T = int(input())
 
for tc in range(1, T + 1):
 
    test_num = int(input())
 
    scores = list(map(int, input().split()))
 
    count = [0] * 101
 
     
    for score in scores:
        count[score] += 1
 
    max_count = 0
    answer = 0
 
     
    for i in range(101):
 
         
         
        if count[i] >= max_count:
            max_count = count[i]
            answer = i
 
    print(f"#{test_num} {answer}")
