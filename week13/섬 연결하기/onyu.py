def solution(n, costs):
    answer = 0

    def find(x):
        if root[x] != x:
            root[x] = find(root[x])
        return root[x]
    
    def union(x, y):
        x = find(x)
        y = find(y)
        if x > y:
            root[x] = y
        else:
            root[y] = x        
    
    root = [0]*n
    for i in range(n):
        root[i] = i
    
    costs.sort(key=lambda x:x[2])

    for cost in costs:
        a, b, c = cost
        if find(a) != find(b):
            union(a, b)
            answer += c
    
    return answer