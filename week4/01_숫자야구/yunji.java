import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());


        Queue<int []> list = new ArrayDeque<>();
        for(int i = 1 ; i < 10; i++){
            for(int j = 1 ; j < 10; j++){
                if(i == j) continue;
                for(int k = 1 ; k < 10; k++){
                    if(i == k || j == k) continue;
                    list.add(new int[]{i,j,k});
                }
            }
        }

        for(int i = 0 ; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String number = st.nextToken();
            int [] num = new int[3];
            for(int j = 0 ; j < 3; j++){
                num[j] = number.charAt(j) - '0';
            }
            int strike = Integer.parseInt(st.nextToken());
            int ball = Integer.parseInt(st.nextToken());

            int size = list.size();
            for(int j = 0 ; j < size; j++){
                int [] curr = list.poll();

                int sN = strikeNum(curr, num);
                int bN = ballNum(curr, num);

                if(strike == sN && bN == ball) list.add(curr);
            }


        }

        sb.append(list.size());
        System.out.println(sb.toString());
    } // end of main
    public static int strikeNum(int [] curr, int [] num){
        int cnt = 0;
        for(int i = 0 ; i < 3; i++){
            if(curr[i] == num[i]) cnt++;
        }
        return cnt;
    }
    public static int ballNum(int [] curr, int [] num){
        int cnt = 0;
        if(curr[0] == num[1]) cnt++;
        if(curr[0] == num[2]) cnt++;
        if(curr[1] == num[2]) cnt++;
        if(curr[1] == num[0]) cnt++;
        if(curr[2] == num[0]) cnt++;
        if(curr[2] == num[1]) cnt++;

        return cnt;
    }
}// end of class
