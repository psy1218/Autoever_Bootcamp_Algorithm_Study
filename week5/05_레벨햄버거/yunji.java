import java.util.*;
import java.io.*;

public class Main {
    static long[] patty;
    static long[] len;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        long X = Long.parseLong(st.nextToken());

        build(N);

        long answer = levelHambuger(N, X);

        System.out.println(answer);
    } // end of main
    static void build(int N){
        patty = new long[N+1];
        len = new long[N+1];

        patty[0] = 1;
        len[0] = 1;

        for(int i = 1 ; i <= N; i++){
            patty[i] = patty[i-1] * 2 + 1;
            len[i] = len[i-1] * 2 + 3;
        }
    }
    static long levelHambuger(int n, long x){
        //레벨 0까지 0이면 패티 0 1이면 패티 1
        if(n == 0){
            if(x == 1) return 1;
            return 0;
        }

        if(x == 1) return 0; // 첫번째는 무조건 빵

        // 왼쪽영역에 존재
        if(x <= 1 + len[n-1]){
            return levelHambuger(n-1, x-1);
        }

        // 가운데 패티
        if(x == 1 +len[n-1] +1){
            return patty[n-1] + 1;
        }

        // 오른쪽 영역에 존재
        if(x <= 1 + len[n-1] + 1 + len[n-1]){
            return patty[n-1]+1+levelHambuger(n-1, x - (len[n-1] + 2));
        }

        return patty[n]; // 마지막빵을 가리키면 다먹은거
    }
} // end of class