import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        int [] arr = new int[N];
        for(int i = 0 ; i < N; i++){
            arr[i] = Integer.parseInt(br.readLine());
        }

        int root = arr[N-1];
        int cnt = 1;
        for(int i = N-2 ; i  >= 0; i--){
            if(arr[i] > root) {
                root = arr[i];
                cnt++;
            }
        }

        sb.append(cnt);
        System.out.print(sb.toString());

    } // end of main
}// end of class
