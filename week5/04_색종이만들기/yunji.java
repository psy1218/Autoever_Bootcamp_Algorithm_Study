import java.util.*;
import java.io.*;

public class Main {
    static int [] answer ;
    static int [][] arr;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        arr = new int[N][N];

        for(int i = 0 ; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j < N; j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 0이 white, 1이 blue
        answer = new int[2];

        tearPaper(0, 0, N-1, N-1);

        sb.append(answer[0]).append("\n").append(answer[1]);

        System.out.println(sb.toString());
    } // end of main
    static void tearPaper(int lx, int ly, int rx, int ry){
        int result = isOnePiece(lx, ly, rx, ry);
        if(result >= 0){
            answer[result]++;
            return;
        }

        int mx = (lx + rx) / 2;
        int my = (ly + ry) / 2;

        tearPaper(lx, ly, mx, my);
        tearPaper(lx, my+1, mx, ry);
        tearPaper(mx+1, ly, rx, my);
        tearPaper(mx+1, my+1, rx, ry);
    }
    static int isOnePiece(int lx, int ly, int rx, int ry){
        int root = arr[lx][ly];
        for(int i = lx ; i <=rx; i++){
            for(int j = ly; j <= ry; j++){
                if(root != arr[i][j]) return -1;
            }
        }
        return root;
    }
} // end of class