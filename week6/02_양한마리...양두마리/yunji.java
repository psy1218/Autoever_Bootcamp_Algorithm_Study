import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for(int t = 0 ; t < T; t++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int H = Integer.parseInt(st.nextToken());
            int W = Integer.parseInt(st.nextToken());

            char [][] map = new char [H][W];
            for(int i = 0 ; i < H; i++){
                String str = br.readLine();
                for(int j = 0 ; j < W; j++){
                    map[i][j] = str.charAt(j);

                }
            }
            int cnt = 0;
            boolean [][] isVisit = new boolean[H][W];

            Queue<int []> queue = new ArrayDeque<>();

            int [] dr = {-1, 1, 0, 0};
            int [] dc = {0, 0, -1, 1};

            for(int i = 0 ; i < H; i++){
                for(int j = 0 ; j < W; j++){
                    if(map[i][j] == '.' || isVisit[i][j]) continue;
                    cnt++;

                    queue.add(new int [] {i,j});

                    while(!queue.isEmpty()){
                        int [] curr = queue.poll();

                        for(int d = 0 ; d < 4; d++){
                            int nr = curr[0] + dr[d];
                            int nc = curr[1] + dc[d];

                            if(nr < 0 || nc < 0 || nr >= H || nc >= W || isVisit[nr][nc] || map[nr][nc] == '.') continue;
                            isVisit[nr][nc] = true;
                            queue.add(new int[] {nr, nc});
                        }
                    }
                }
            }

            sb.append(cnt).append("\n");
        }// end of T

        System.out.println(sb.toString());

    } // end of main
} // end of class