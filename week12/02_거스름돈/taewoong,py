def solution(n, money):
    
    dp = [1] + [0] * (n)
    
    for j in money:
        for i in range(m,n+1):
            dp[i] += dp[i - j]
            
    return dp[n % 1000000007]
