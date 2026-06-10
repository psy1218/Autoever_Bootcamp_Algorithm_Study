import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int K = Integer.parseInt(br.readLine());

        int [] Adp = new int[K+1];
        int [] Bdp = new int[K+1];

        Adp[0] = 1;
        Bdp[0] = 0;

        for(int i = 1; i <= K ; i++){
            Adp[i] = Bdp[i-1];
            Bdp[i] = Adp[i-1] + Bdp[i-1];
        }

        sb.append(Adp[K] + " " + Bdp[K]);
        System.out.println(sb.toString());

    } // end of main
} // end of class

