def solution(stones, k):
    l = 1
    r = 200000000
    while l <= r:
        check = stones.copy()
        m = (l + r) // 2 #건널수잇는사람 체크
        count = 0 #연속으로 못밟는 돌 갯수
        for t in check:
            if t - m <= 0: #돌을 더이상 밟을 수 없으면
                count += 1
            else:
                count = 0
            if count >= k: #연속으로 건너뛰어야하는게 k개 이상이면 
                break
        if count >= k: #m명 실패
            r = m - 1
        else:
            l = m + 1
        
    return l
