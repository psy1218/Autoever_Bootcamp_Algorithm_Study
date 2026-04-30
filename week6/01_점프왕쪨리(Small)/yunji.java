import java.util.*;
import java.io.*;

public class Main {
    static int [][] map;
    static int N;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());

        map = new int[N][N];
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j < N; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        isPos = false;
        runJelly(0,0);

        if(isPos) sb.append("HaruHaru");
        else sb.append("Hing");

        System.out.println(sb.toString());

    } // end of main
    static boolean isPos;
    static void runJelly(int r, int c){
        if(isPos) return;
        int jumpNum = map[r][c];
        if(jumpNum == 0){
            return;
        }

        if(jumpNum == -1) {
            isPos = true;
            return;
        }

        if(r + jumpNum < N){
            runJelly(r+jumpNum, c);
        }

        if(c + jumpNum < N){
            runJelly(r, c+jumpNum);
        }

    } // end of runJelly

} // end of class