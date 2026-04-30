import java.util.*;
import java.io.*;

public class Main {
    static long [][] dp;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        dp = new long[31][31];

        dp[0][0] = 1;

        while(true){
            int N = Integer.parseInt(br.readLine());
            if(N == 0) break;

            sb.append(eatPill(N,0)).append("\n");
        }

        System.out.println(sb.toString());

    } // end of main
    static long eatPill(int W, int H ){
        if(W == 0 && H == 0) return 1;

        if(dp[W][H] != 0) return dp[W][H];

        long count = 0L;

        if(W > 0 ) count += eatPill(W-1, H+1);

        if(H > 0) count += eatPill(W, H-1);

        return dp[W][H] = count;


    }
} // end of class

