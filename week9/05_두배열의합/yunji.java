import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        int N = Integer.parseInt(br.readLine());

        int [] prefixA = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0 ; i < N; i++){
            prefixA[i] = Integer.parseInt(st.nextToken());
            if(i != 0) prefixA[i] += prefixA[i-1];
        }

        int M = Integer.parseInt(br.readLine());

        int [] prefixB = new int[M];
        st = new StringTokenizer(br.readLine());
        for(int i = 0 ; i < M; i++){
            prefixB[i] = Integer.parseInt(st.nextToken());
            if(i != 0) prefixB[i] += prefixB[i-1];
        }

        HashMap<Integer, Integer> hmA = new HashMap<>();
        for(int i = 0 ; i < N; i++){
            hmA.put(prefixA[i], hmA.getOrDefault(prefixA[i], 0) + 1);
            for(int j = 0; j < i; j++){
                hmA.put(prefixA[i] - prefixA[j], hmA.getOrDefault(prefixA[i] - prefixA[j], 0) + 1);
            }
        }

        HashMap<Integer, Integer> hmB = new HashMap<>();
        for(int i = 0 ; i < M; i++){
            hmB.put(prefixB[i], hmB.getOrDefault(prefixB[i], 0) + 1);
            for(int j = 0; j < i; j++){
                hmB.put(prefixB[i] - prefixB[j], hmB.getOrDefault(prefixB[i] - prefixB[j], 0) + 1);
            }
        }


        long cnt = 0;
        for(int x : hmA.keySet()){
            if(hmB.containsKey(T-x)) {
                cnt += (long) hmA.get(x) * hmB.get(T-x);
            }
        }

        sb.append(cnt);

        System.out.println(sb.toString());

    } // end of main

} // end of class

