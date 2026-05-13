import heapq

def solution(n, k, enemy):
    
    heap = []
    result = 0
    count = 0
    for i in enemy:
        heapq.heappush(heap, -i)#파이썬 heapq는 최소힙이라서 -i로 최대힙 처럼 사용
        #=>가장 큰 적수를 바로 꺼낼라고
        count += i #현재 라운드 적 수를 병사로 막음
        if count > n:#병사 수 초과시
            if not k:
                return result
            count += heapq.heappop(heap)#무적권 사용=>지금까지 나온 적 중 가장 큰적에 무적권 사용
            k-=1
        result += 1
                
    return result
