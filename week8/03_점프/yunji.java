import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        int [][] map = new int[N][N];
        for(int i = 0 ; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j < N; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        long [][] dp  = new long [N][N];
        dp[0][0] = 1;

        for(int i = 0 ; i < N; i++){
            for(int j = 0 ; j < N; j++){
                if(dp[i][j] ==0) continue;
                if(i == N-1 && j == N-1) continue;

                int step = map[i][j];

                if(i + step < N) {
                    dp[i + step][j] += dp[i][j];
                }
                if(j+ step < N){
                    dp[i][j+step] += dp[i][j];
                }

            }
        }

        sb.append(dp[N-1][N-1]);
        System.out.println(sb.toString());

    } // end of main
} // end of class

