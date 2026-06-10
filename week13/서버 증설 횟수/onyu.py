from collections import deque

def solution(players, m, k):
    answer = 0
    servers = deque()
    count = 0
    over = 0
    for player in players:

        if servers:
            for i in range(len(servers)):
                servers[i] += 1
                if servers[i] >= k:
                    over += 1

            if over > 0:
                for _ in range(over):
                    servers.popleft()
                over = 0

        need = player // m
        if need > 0 and need > len(servers):
            for _ in range(need - len(servers)):
                servers.append(0) 
                count += 1
    return count
