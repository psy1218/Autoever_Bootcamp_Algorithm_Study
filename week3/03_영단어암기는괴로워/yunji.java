import java.util.*;
import java.io.*;

public class Main {
    static class Word implements Comparable<Word>{
        String word;
        int frequency;
        int length;

        public Word(String word, int frequency, int length) {
            this.word = word;
            this.frequency = frequency;
            this.length = length;

        }

        @Override
        public int compareTo(Word o){
            if(this.frequency == o.frequency){
                if(this.length == o.length) return this.word.compareTo(o.word);
                return o.length - this.length;
            }
            return o.frequency - this.frequency;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        HashMap<String, Integer> hm = new HashMap<>();
        for(int i = 0 ; i < N; i++){
            String word = br.readLine();
            if(word.length() < M) continue;
            hm.put(word, hm.getOrDefault(word, 0)+ 1);
        }

        List<Word> wordList = new ArrayList<>();
        for(String key : hm.keySet()){
            int keyFrequency = hm.get(key);
            int keyLength = key.length();

            wordList.add(new Word(key, keyFrequency, keyLength));
        }

        Collections.sort(wordList);
        for(Word word : wordList){
            sb.append(word.word).append("\n");
        }
        System.out.print(sb.toString());

    } // end of main
}// end of class
