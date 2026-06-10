import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        int [] dp = new int[N+1];
        Arrays.fill(dp, Integer.MAX_VALUE);

        if(N < 5){
            if(N == 1 || N == 3) {
                System.out.println(-1);
            }else if(N == 2){
                System.out.println(1);
            }else if(N == 4){
                System.out.println(2);
            }
            return;
        }
        dp[2] = 1;
        dp[4] = 2;
        dp[5] = 1;

        for(int i = 6; i <= N; i++){
            int minus2 = dp[i-2];
            int minus5 = dp[i-5];

            if(minus2 == Integer.MAX_VALUE && minus5 == Integer.MAX_VALUE) continue;

            dp[i] = Math.min(minus2,minus5) + 1;
        }

        if(dp[N] == Integer.MAX_VALUE) sb.append(-1);
        else sb.append(dp[N]);

        System.out.println(sb.toString());

    } // end of main
} // end of class

