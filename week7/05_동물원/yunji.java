import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();


        int N = Integer.parseInt(br.readLine());

        long [][] dp = new long [N][3];

        int mod = 9901;
        for(int i = 0; i <3; i++){
            dp[0][i] = 1;
        }
        for(int i = 1; i < N; i++){
            dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%mod;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2])%mod;
            dp[i][2] = (dp[i-1][0] + dp[i-1][1])%mod;
        }

        long result = 0;
        for(int i = 0 ; i < 3 ; i++){
            result += dp[N-1][i];
        }

        sb.append(result%mod);
        System.out.print(sb.toString());

    } // end of main
}// end of class
