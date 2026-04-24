from collections import deque

def solution(stones, k):
    answer = 0

    start, end = 0, max(stones)
    while start <= end:
        mid = (start+end)//2
        count = 0
        for s in stones:
            if s <= mid:
                count += 1
            else: 
                count = 0
            if count >= k:
                answer = mid
                break
        if answer == mid:
            end = mid - 1
        else:
            start = mid + 1
        
    return answer
