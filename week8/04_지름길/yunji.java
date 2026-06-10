import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());

        int [] dp = new int[D+1];
        List<List<int []>> list = new ArrayList<>();
        for(int i = 0 ; i <= D; i++) list.add(new ArrayList<>());

        for(int i = 0 ; i <= D; i++) dp[i] = i;
        for(int i = 0 ; i < N; i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int dis = Integer.parseInt(st.nextToken());

            if(end > D) continue;
            if(end - start <= dis) continue;

            list.get(start).add(new int []{end, dis});
        }

        for(int i = 0 ; i < D; i++){
            dp[i+1] = Math.min(dp[i+1], dp[i] + 1);

            for(int [] x : list.get(i)){
                int e = x[0];
                int w = x[1];

                dp[e] = Math.min(w + dp[i], dp[e]);

            }
        }

        sb.append(dp[D]);
        System.out.println(sb.toString());

    } // end of main
} // end of class

