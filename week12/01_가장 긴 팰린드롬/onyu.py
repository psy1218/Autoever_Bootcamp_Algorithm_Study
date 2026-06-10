def solution(s):
    answer = 0
    
    def pal(start, end):
        while 0<=start and end<len(s) and s[start] == s[end]:
            start -= 1
            end += 1
        return end - start - 1 
    
    for i in range(len(s)):
        answer = max(answer, pal(i, i))
        answer = max(answer, pal(i, i+1))
    return answer