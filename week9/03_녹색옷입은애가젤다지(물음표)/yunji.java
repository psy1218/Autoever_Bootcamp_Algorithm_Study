import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int index = 1;
        while(true){
            int N = Integer.parseInt(br.readLine());

            if(N == 0) break;

            int [][] map = new int[N][N];
            for(int i = 0 ; i < N; i++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                for(int j = 0 ; j < N; j++){
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            PriorityQueue<int []> pq = new PriorityQueue<>((a,b)->{
                return a[2] - b[2];
            });

            int [] dr = {-1, 1, 0, 0};
            int [] dc = {0, 0, -1, 1};

            pq.add(new int[]{0, 0, map[0][0]});
            int [][] dp = new int[N][N];
            int INF = 1_000_000_000;
            for(int i = 0 ; i < N; i++) Arrays.fill(dp[i], INF);
            dp[0][0] = map[0][0];

            while(!pq.isEmpty()){
                int [] curr = pq.poll();
                if(dp[curr[0]][curr[1]] != curr[2]) continue;

                for(int d = 0; d < 4; d++){
                    int nr = curr[0] + dr[d];
                    int nc = curr[1] + dc[d];

                    if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
                    if(dp[nr][nc] > curr[2] + map[nr][nc]){
                        dp[nr][nc] = curr[2] + map[nr][nc];
                        pq.add(new int[]{nr, nc, dp[nr][nc]});
                    }
                }
            }

            sb.append("Problem " + index + ": " + dp[N-1][N-1]).append("\n");

            index++;
        }

        System.out.println(sb.toString());

    } // end of main
} // end of class

