def solution(scores):
    answer = 1
    aa, bb = scores[0]
    score = aa + bb
    scores.sort(key = lambda x:(-x[0], x[1]))
    bbb = 0
    for a, b in scores:
        if a > aa and b > bb:
            return -1
        if b >= bbb:
            bbb = b
            if a + b > score:
                answer += 1
    return answer
