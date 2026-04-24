def solution(user_id, banned_id):
    answer = 0
    
    candidate = []
    for ban in banned_id:
        temp = []
        for user in user_id:
            if len(user) == len(ban):
                check = 0
                for i in range(len(user)):
                    if user[i] != ban[i] and ban[i] != '*':
                        check = 1
                        break
                if check == 0:
                    temp.append(user)
        candidate.append(temp)
    
    
    answer_set = set()
    def dfs(i, arr):
        if i == len(banned_id):
            answer_set.add(tuple(sorted(arr)))
            return
        
        for user in candidate[i]:
            if user not in arr:
                arr.append(user)
                dfs(i+1, arr)
                arr.pop()
        
        
    dfs(0, [])
    return len(answer_set)