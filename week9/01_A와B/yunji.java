import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        long xs = Integer.parseInt(st.nextToken());
        long ys = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        long xe = Integer.parseInt(st.nextToken());
        long ye = Integer.parseInt(st.nextToken());

        long minValue = Math.abs(xe - xs) + Math.abs(ye - ys);

        long [][] tel = new long[6][4];
        for(int i = 0 ; i < 3; i++){
            st= new StringTokenizer(br.readLine());
            tel[i][0] = Integer.parseInt(st.nextToken());
            tel[i][1] = Integer.parseInt(st.nextToken());
            tel[i][2] = Integer.parseInt(st.nextToken());
            tel[i][3] = Integer.parseInt(st.nextToken());
        }

        for(int i = 3; i < 6; i++){
            tel[i][0] = tel[i-3][2];
            tel[i][1] = tel[i-3][3];
            tel[i][2] = tel[i-3][0];
            tel[i][3] = tel[i-3][1];
        }

        for(int i = 0 ; i <6; i++){
            long s_t1 = Math.abs(tel[i][0] - xs) + Math.abs(tel[i][1] - ys);
            long t1_e = Math.abs(tel[i][2] - xe) + Math.abs(tel[i][3] - ye);

            minValue = Math.min(minValue, s_t1+t1_e + 10);

        }



        for(int i = 0 ; i < 6; i++){
            for(int j = 0 ; j <6; j++){
                if(j == i) continue;
                long s_t1 = Math.abs(tel[i][0] - xs) + Math.abs(tel[i][1] - ys);;
                long t1_t2 = Math.abs(tel[i][2] - tel[j][0]) + Math.abs(tel[i][3] - tel[j][1]);
                long t2_e = Math.abs(tel[j][2] - xe) + Math.abs(tel[j][3] - ye);

                minValue = Math.min(minValue, s_t1+t1_t2+t2_e + 20);
            }
        }

        for(int i = 0 ; i < 6; i++){
            for(int j = 0 ; j <6; j++){
                if(i == j) continue;
                for(int k = 0 ; k <6; k++){
                    if(k == j || k ==i)continue;

                    long s_t1 = Math.abs(tel[i][0] - xs) + Math.abs(tel[i][1] - ys);;
                    long t1_t2 = Math.abs(tel[i][2] - tel[j][0]) + Math.abs(tel[i][3] - tel[j][1]);
                    long t2_t3 = Math.abs(tel[j][2] - tel[k][0]) + Math.abs(tel[j][3] - tel[k][1]);
                    long t3_e = Math.abs(tel[k][2] - xe) + Math.abs(tel[k][3] - ye);

                    minValue = Math.min(minValue, s_t1+t1_t2+t2_t3+t3_e + 30);

                }
            }
        }



        sb.append(minValue);
        System.out.println(sb.toString());

    } // end of main
} // end of class

