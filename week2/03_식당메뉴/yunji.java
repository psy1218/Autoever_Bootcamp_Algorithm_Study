import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());

        Queue<int []> queue = new LinkedList<>();
        List<Integer> A = new ArrayList<>();
        List<Integer> B = new ArrayList<>();
        List<Integer> C = new ArrayList<>();

        for(int i = 0 ; i < n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int type = Integer.parseInt(st.nextToken());

            if(type == 1){
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                queue.add(new int [] {a,b});

            }else{
                int a = Integer.parseInt(st.nextToken());

                int [] curr = queue.poll();
                if(curr[1] == a) A.add(curr[0]);
                else B.add(curr[0]);

            }
        }
        while(!queue.isEmpty()){
            int [] curr = queue.poll();

            C.add(curr[0]);
        }
        Collections.sort(A);
        Collections.sort(B);
        Collections.sort(C);

        if(A.isEmpty()) sb.append("None");
        else{
            for(int i = 0 ; i <A.size() ; i++){
                sb.append(A.get(i) + " ");
            }
        }
        sb.append("\n");
        if(B.isEmpty()) sb.append("None");
        else{
            for(int i = 0 ; i <B.size() ; i++){
                sb.append(B.get(i) + " ");
            }
        }
        sb.append("\n");
        if(C.isEmpty()) sb.append("None");
        else{
            for(int i = 0 ; i <C.size() ; i++){
                sb.append(C.get(i) + " ");
            }
        }

        System.out.print(sb.toString());

    } // end of main
}// end of class
