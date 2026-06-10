import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for(int t = 0; t < T; t++) {
            int N = Integer.parseInt(br.readLine());

            List<int []> list = new ArrayList<>();
            for(int i = 0 ; i < N; i++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                int submit = Integer.parseInt(st.nextToken());
                int interview = Integer.parseInt(st.nextToken());

                list.add(new int[] {submit, interview});
            }
            Collections.sort(list, (a,b)->{
                if(a[0] == b[0]) return a[1] - b[1];
                return a[0] - b[0];
            });

            int line = list.get(0)[1];
            int cnt = 0;

            for(int i = 1; i < N; i++){
                if(list.get(i)[1] > line) cnt++;
                else line = Math.min(line, list.get(i)[1]);
            }
            sb.append(N - cnt).append("\n");
        }

        System.out.print(sb.toString());

    } // end of main
}// end of class
