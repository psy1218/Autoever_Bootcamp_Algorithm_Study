
for tc in range(10):
    N = int(input())
    a = list(map(str, input()))
    arr = list()

   
    left = ['(', '{', '[', '<']
    
    right = [')', '}', ']', '>']
    for i in range(N):
        if a[i] in left:
            arr.append(lst[i])
        if a[i] in right:
            
            if right.index(a[i]) == left.index(arr[-1]):
                
                arr.pop()   
            else:
                break
                
    sol = 0
    if len(arr) == 0:
        sol = 1
    
    print("#{} {}".format(tc + 1, sol))

