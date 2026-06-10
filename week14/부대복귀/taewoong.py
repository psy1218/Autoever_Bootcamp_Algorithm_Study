from collections import deque

def solution(n, roads, sources, destination):
    graph = [[] for _ in range(n + 1)]

    for a, b in roads:
        graph[a].append(b)
        graph[b].append(a)

    distance = [-1] * (n + 1)
    queue = deque()

    distance[destination] = 0
    queue.append(destination)

    while queue:
        now = queue.popleft()

        for next_node in graph[now]:
            if distance[next_node] == -1:
                distance[next_node] = distance[now] + 1
                queue.append(next_node)

    answer = []
    
    for source in sources:
        answer.append(distance[source])

    return answer
