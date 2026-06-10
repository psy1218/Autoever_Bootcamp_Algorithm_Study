import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());

        arr = new int[N][2];

        for(int i = 0 ; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }

        min = Integer.MAX_VALUE;

        for(int i = 1; i <= N; i++){
            findSequence(0, 0, i, new int[i]);
        }

        sb.append(min);
        System.out.println(sb.toString());

    } // end of main
    static int N, min;
    static int [][] arr;
    public static void findSequence(int cnt, int id, int maxId, int[] curr){
        if(cnt == maxId){
            long s = arr[curr[0]][0];
            long ss = arr[curr[0]][1];
            for(int i = 1 ; i <maxId; i++){
                s *= arr[curr[i]][0];
                ss += arr[curr[i]][1];
            }
            min = Math.min(min, (int) Math.abs(s - ss));
            return;
        }

        for(int i = id ; i < N; i++){
            curr[cnt] = i;
            findSequence(cnt+1, i+1, maxId, curr);
        }

    }

} // end of class

