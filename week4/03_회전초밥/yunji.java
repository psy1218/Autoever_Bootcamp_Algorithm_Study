import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        Queue<Integer>[] sushi = new Queue[200001];

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());

            for(int j = 0; j < k; j++){
                int type = Integer.parseInt(st.nextToken());

                if(sushi[type] == null){
                    sushi[type] = new ArrayDeque<>();
                }
                sushi[type].add(i);
            }
        }

        int[] cnt = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < M; i++){
            int type = Integer.parseInt(st.nextToken());

            if(sushi[type] != null && !sushi[type].isEmpty()){
                int person = sushi[type].poll();
                cnt[person]++;
            }
        }


        for(int i = 0; i < N; i++){
            sb.append(cnt[i]).append(" ");
        }

        System.out.println(sb);
    }// end of main
} // end of class