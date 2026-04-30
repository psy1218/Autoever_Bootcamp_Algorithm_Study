import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        int K = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        int [] map = new int[N];
        for(int i = 0; i < N; i++) {
            map[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(map);

        if(K >= N) {
            System.out.println(0);
            return;
        }
        int minDis = map[N-1] - map[0];
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for(int i = 1; i < N; i++){
            pq.add(map[i] - map[i-1]);
        }

        for(int i = 0 ; i < K-1; i++){
            minDis -= pq.poll();
        }
        sb.append(minDis);
        System.out.print(sb.toString());

    } // end of main
}// end of class
