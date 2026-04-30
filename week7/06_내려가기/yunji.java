import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();


        int N = Integer.parseInt(br.readLine());

        int [][] map = new int [N][3];

        for(int i = 0 ; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j < 3; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int [][] minDp = new int [N][3];
        int [][] maxDp = new int [N][3];

        for(int i = 0 ; i < N; i++) Arrays.fill(minDp[i], Integer.MAX_VALUE);

        for(int i = 0 ; i < 3; i++){
            minDp[0][i] = map[0][i];
            maxDp[0][i] = map[0][i];
        }
        for(int i = 1 ; i < N; i++){
            minDp[i][0] = map[i][0] + Math.min(minDp[i-1][0], minDp[i-1][1]);
            maxDp[i][0] = map[i][0] + Math.max(maxDp[i-1][0], maxDp[i-1][1]);

            minDp[i][1] = map[i][1] + Math.min(minDp[i-1][0], Math.min(minDp[i-1][1], minDp[i-1][2]));
            maxDp[i][1] = map[i][1] + Math.max(maxDp[i-1][0], Math.max(maxDp[i-1][1], maxDp[i-1][2]));

            minDp[i][2] = map[i][2] + Math.min(minDp[i-1][2], minDp[i-1][1]);
            maxDp[i][2] = map[i][2] + Math.max(maxDp[i-1][2], maxDp[i-1][1]);
        }

        int maxValue = Integer.MIN_VALUE;
        int minValue = Integer.MAX_VALUE;

        for(int i = 0 ; i < 3; i++){
            maxValue = Math.max(maxValue, maxDp[N-1][i]);
            minValue = Math.min(minValue, minDp[N-1][i]);
        }

        sb.append(maxValue).append(" ").append(minValue);
        System.out.print(sb.toString());

    } // end of main
}// end of class
