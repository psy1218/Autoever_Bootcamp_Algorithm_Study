import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        int L = 4 * N - 3;
        int[][] arr = new int[L][L];

        for(int i = 0 ; i < N ; i++){

            int start = 2 * i;
            int end = L - 1 - 2 * i;

            for(int r = start ; r <= end ; r++){
                for(int c = start ; c <= end ; c++){
                    if(r == start || r == end || c == start || c == end){
                        arr[r][c] = 1;
                    }
                }
            }
        }

        for(int i = 0 ; i < L; i++){
            for(int j = 0 ; j < L; j++){
                if(arr[i][j] == 1) sb.append("*");
                else sb.append(" ");
            }
            sb.append("\n");
        }

        System.out.println(sb.toString());
    } // end of main
} // end of class