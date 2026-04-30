import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        int small = Integer.parseInt(st.nextToken());
        int add = 0;
        for(int i = 1 ; i < N; i++){
            int big = Integer.parseInt(st.nextToken());

            int dif = big - small;
            pq.add(dif);
            add += dif;

            small = big;
        }

        for(int i = 0 ; i < K-1; i++){
            add -= pq.poll();
        }


        System.out.println(add);
    }// end of main
} // end of class