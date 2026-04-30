import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int [][] map = new int [N][M];
        for(int i = 0 ; i < N; i++){
            String str = br.readLine();
            for(int j = 0 ; j < M; j++){
                map[i][j] = str.charAt(j) - '0';
            }
        }

        Queue<int []> queue = new ArrayDeque<>();
        boolean [][] isVisit = new boolean[N][M];

        int [] dr = {-1, 1, 0, 0};
        int [] dc = {0, 0, -1, 1};

        for(int i = 0 ; i < M; i++){
            if(map[0][i] == 1 || isVisit[0][i]) continue;

            queue.add(new int[]{0,i});

            while(!queue.isEmpty()){
                int [] curr = queue.poll();

                for(int d = 0 ; d < 4; d++){
                    int nr = curr[0] + dr[d];
                    int nc = curr[1] + dc[d];

                    if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
                    if(isVisit[nr][nc] || map[nr][nc] == 1) continue;
                    if(nr == N-1) {
                        System.out.println("YES");
                        return;
                    }

                    isVisit[nr][nc] = true;
                    queue.add(new int [] {nr, nc});
                }
            }
        }

        System.out.println("NO");

    } // end of main
} // end of class