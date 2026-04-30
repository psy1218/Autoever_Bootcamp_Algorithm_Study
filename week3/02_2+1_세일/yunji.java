import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());

        for(int i = 0 ; i < N; i++){
            int price = Integer.parseInt(br.readLine());
            pq.add(price);
        }

        int needPrice = 0;
        while(pq.size() >= 3){
            for(int i = 0 ; i < 2; i++){
                needPrice += pq.poll();
            }
            pq.poll();
        }

        while(!pq.isEmpty()){
            needPrice += pq.poll();
        }

        sb.append(needPrice).append("\n");
        System.out.print(sb.toString());

    } // end of main
}// end of class
