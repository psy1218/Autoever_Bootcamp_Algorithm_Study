import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int [] truck = new int[n];
        for (int i = 0; i < n; i++) {
            truck[i] = Integer.parseInt(st.nextToken());
        }

        int time = 0;
        Queue<Integer> queue = new ArrayDeque<>();
        for(int i = 0 ; i < w; i++) queue.add(0);
        int index = 0;
        int addTruck = 0;

        while(!queue.isEmpty()){
            int curr = queue.poll();
            addTruck -= curr;
            if(index < n){
                if(addTruck + truck[index] <= L){
                    addTruck += truck[index];
                    queue.add(truck[index++]);
                }else{
                    queue.add(0);
                }
            }

            time++;
        }


        sb.append(time);
        System.out.print(sb.toString());

    } // end of main
}// end of class
