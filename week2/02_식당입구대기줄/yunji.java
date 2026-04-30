import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());


        int [] line = new int[n];
        int start = 0; int end = -1; ;
        int maxValue = 0;
        int lastNum = Integer.MAX_VALUE;

        for(int i = 0 ; i < n ;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());



            if(a == 1){
                int id = Integer.parseInt(st.nextToken());
                line[++end] = id;
                if(end - start >= maxValue){
                    if(end - start == maxValue){
                        if(line[end] < lastNum){
                            lastNum = line[end];
                        }
                    }else{
                        lastNum = line[end];
                    }
                    maxValue = end - start ;
                }
            }else{
                start++;
            }

        }

        sb.append(maxValue + 1 + " " + lastNum);
        System.out.print(sb.toString());

    } // end of main
}// end of class
