import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        N= Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0 ; i < N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);


        findSequence(0, 0, new int[M]);

        System.out.println(sb.toString());

    } // end of main
    static int N,M;
    static StringBuilder sb;
    static int [] arr;
    public static void findSequence(int cnt, int id, int[] curr){
        if(cnt == M){
            for(int i = 0  ;i <M; i++){
                sb.append(curr[i]).append(" ");
            }
            sb.append("\n");
            return;
        }

        for(int i = id ; i < N; i++){
            curr[cnt] = arr[i];
            findSequence(cnt+1, i, curr);
        }
    }

} // end of class

