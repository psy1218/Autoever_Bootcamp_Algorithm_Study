import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        arr = new int [N+1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        isPal = new int [N+1][N+1];

        int M = Integer.parseInt(br.readLine());
        for(int i = 0 ; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            isPalindrome(start, end);

            if(isPal[start][end] == 1) sb.append(1).append("\n");
            else sb.append(0).append("\n");

        }
        System.out.println(sb.toString());

    } // end of main

    static int [][] isPal;
    static int [] arr;
    public static int isPalindrome(int start, int end){
        if(isPal[start][end] == 1) return 1;
        if(isPal[start][end] == -1) return -1;
        if(start == end) return isPal[start][end] = 1;

        if(arr[start] != arr[end]){
            return isPal[start][end] = -1;
        } else{
            if(start + 1 < end -1){
                return isPal[start][end] = isPalindrome(start + 1, end - 1);
            }
        }

        return isPal[start][end] = 1;
    }
} // end of class

