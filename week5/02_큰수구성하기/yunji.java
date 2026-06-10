import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        String number = st.nextToken();
        N = number.length();
        topItems = new int[N];
        for(int i = 0 ; i < N ;i++){
            topItems[i] = number.charAt(i) - '0';
        }

        K = Integer.parseInt(st.nextToken());

        items = new int [K];
        st = new StringTokenizer(br.readLine());
        for(int i = 0 ; i < K; i++){
            items[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(items);

        end = false;
        int [] result = new int [N];
        answer = -1;
        findMaxValue(result, 0, false);

        if(answer == -1){
            for(int i = 0 ;  i< N-1; i++){
                sb.append(items[K-1]);
            }

            answer = Integer.parseInt(sb.toString());
        }

        System.out.println(answer);
    }// end of main
    static int [] topItems, items;
    static int N, K, answer;
    static boolean end;
    public static void findMaxValue(int [] result , int index, boolean isTopLow){
        if(end) return;
        if(index == N) {
            StringBuilder sb = new StringBuilder();
            for(int i = 0 ; i < N; i++){
                sb.append(result[i]);
            }

            end = true;
            answer = Integer.parseInt(sb.toString());
            return;

        }


        for(int j = K-1; j >=0 ; j--){
            if(isTopLow){
                result[index] = items[j];
                findMaxValue(result, index + 1, true);
                continue;
            }
            if(topItems[index]  < items[j]) continue;
            result[index] = items[j];
            if(topItems[index] == items[j]) findMaxValue(result, index+1, isTopLow);
            else findMaxValue(result, index + 1, true);


        }

    } // end of findMaxValue
}// end of class