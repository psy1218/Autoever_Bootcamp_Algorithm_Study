def solution(players, m, k):
    server=[0]*24 
    count=0 
    
    for i in range(24):
        num=players[i]//m #해당시간에 서버 몇개 필요함?
        
        if num>server[i]:#현재 만들어진 서버가 부족하면
            count2=num-server[i] 
            count+=count2
            
            for j in range(i, min(i+k, 24)):#현재부터 k번째 까지 서버 추가
                server[j] += count2
            

    return count
