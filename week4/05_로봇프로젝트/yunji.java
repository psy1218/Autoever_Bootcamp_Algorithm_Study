import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true){
            String line = br.readLine();
            if(line == null) break;

            int x = Integer.parseInt(line) * 10_000_000;
            int n = Integer.parseInt(br.readLine());

            int[] arr = new int[n];
            for(int i = 0; i < n; i++){
                arr[i] = Integer.parseInt(br.readLine());
            }

            Arrays.sort(arr);

            int left = 0;
            int right = n - 1;

            boolean found = false;

            while(left < right){
                int sum = arr[left] + arr[right];

                if(sum == x){
                    System.out.println("yes " + arr[left] + " " + arr[right]);
                    found = true;
                    break;
                }
                else if(sum < x){
                    left++;
                }
                else{
                    right--;
                }
            }

            if(!found){
                System.out.println("danger");
            }
        }
    }// end of main
}// end of class