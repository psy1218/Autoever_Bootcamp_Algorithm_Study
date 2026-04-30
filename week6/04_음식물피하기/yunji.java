import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int [] dr = {-1, 1, 0, 0};
        int [] dc = {0, 0, -1, 1};

        Queue<int []> queue = new ArrayDeque<>();

        int [][] map = new int [N][M];
        for(int  i = 0 ; i < K; i++){
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            map[r-1][c-1] = 1;
        }

        boolean [][] isVisit = new boolean[N][M];

        int maxValue = Integer.MIN_VALUE;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M; j++){
                if(map[i][j] == 0 || isVisit[i][j]) continue;

                queue.add(new int[]{i, j});
                isVisit[i][j] = true;
                int cnt = 0;

                while(!queue.isEmpty()){
                    int [] curr = queue.poll();
                    cnt++;

                    for(int d = 0 ; d < 4; d++){
                        int nr = curr[0] + dr[d];
                        int nc = curr[1] + dc[d];

                        if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
                        if(isVisit[nr][nc] || map[nr][nc] == 0) continue;


                        isVisit[nr][nc] = true;
                        queue.add(new int [] {nr, nc});
                    }
                }

                maxValue = Math.max(maxValue, cnt);
            }
        }


        System.out.println(maxValue);

    } // end of main
} // end of class