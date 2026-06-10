import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());


        int cnt = 0;
        int [] topFret = new int[7];
        int [][] nextTop = new int[7][P+1];
        for(int i = 0 ; i < N; i++){
            st = new StringTokenizer(br.readLine());
            int melody = Integer.parseInt(st.nextToken());
            int fret = Integer.parseInt(st.nextToken());

            int f = topFret[melody];

            while(f > fret){
                int nextT = nextTop[melody][f];
                nextTop[melody][f] = 0;
                f = nextT;
                cnt++;
            }

            topFret[melody] = f;

            if(f == fret){
                continue;
            }

            nextTop[melody][fret] = f;
            topFret[melody] = fret;
            cnt++;

        }


        sb.append(cnt);
        System.out.println(sb.toString());
    } // end of main
}// end of class
