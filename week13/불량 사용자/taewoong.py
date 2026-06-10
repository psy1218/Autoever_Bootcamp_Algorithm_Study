def solution(user_id, banned_id):
    answer=0
    import re
    from itertools import permutations
    
    answers = []
    for i in permutations(user_id, len(banned_id)):#전체 유저아이디 수에서 ban아이디 만큼 뽑음
        count = 0
        for j in range(len(i)):
            ban = banned_id[j].replace('*','.')#요거 안바꾸면 *은 앞에 문자가 몇번 반복되는거  체크하게댐
            if re.match(ban,i[j]) and len(ban)==len(i[j]):#패턴하고 길이 마즘?
                count+=1
        if count==len(banned_id):#뽑은 조합이 다 밴목록이랑 겹ㅊ미?
            i = sorted(i)
            if i not in answers:#안겹치면 저장
                answers.append(i)
                
    answer = len(answers)
    
    return answer
