import java.util.*;

class Solution {
    public int solution(int n, int[] money) {
        int answer = 0;

        Arrays.sort(money);

        int num = 0;
        if(n < money[money.length-1]) num = money[money.length-1];
        else num = n;

        int [] dp = new int[num + 1];
        dp[0] = 1;

        for(int i = 0 ; i < money.length; i++){
            int currMoney = money[i];
            for(int j = currMoney ; j <= n; j++){
                dp[j] += dp[j-currMoney];
            }
        }


        return dp[n];
    }
}