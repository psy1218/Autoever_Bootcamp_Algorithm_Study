import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        Queue<Integer> queue = new ArrayDeque<>();


        while(true){
            int curr = Integer.parseInt(br.readLine());
            if(curr == -1) break;
            if(curr == 0) {
                queue.poll();
                continue;
            }
            if(queue.size() < N) queue.add(curr);
        }

        int size = queue.size();
        if(size == 0) sb.append("empty");
        for(int i = 0 ; i < size; i++){
            sb.append(queue.poll()).append(" ");
        }
        System.out.print(sb.toString());

    } // end of main
}// end of class
