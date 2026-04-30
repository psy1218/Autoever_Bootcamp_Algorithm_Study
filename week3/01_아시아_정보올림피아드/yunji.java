import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        PriorityQueue<int []> pq = new PriorityQueue<>((a, b) -> {
            return b[2] - a[2];
        });

        int countryNum = 0;
        for(int i = 0 ; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int countryNo = Integer.parseInt(st.nextToken());
            int studentNo = Integer.parseInt(st.nextToken());
            int score = Integer.parseInt(st.nextToken());

            pq.add(new int[]{countryNo, studentNo, score});
            if(i == N-1) countryNum = countryNo;
        }

        int [] country = new int [countryNum+1];
        int award = 1;
        while(award <= 3){
            int [] person = pq.poll();
            if(country[person[0]] == 2) continue;
            country[person[0]]++;
            award++;
            sb.append(person[0]+ " " + person[1]).append("\n");
        }
        System.out.print(sb.toString());

    } // end of main
}// end of class
