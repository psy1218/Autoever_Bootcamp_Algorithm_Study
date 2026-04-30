import java.util.*;

class Solution {
    class Genres implements Comparable<Genres>{
        String genre;
        int allPlay;

        public Genres(String genre, int allPlay){
            this.genre = genre;
            this.allPlay = allPlay;
        }

        public int compareTo(Genres o){
            return o.allPlay - this.allPlay;
        }
    }
    public int[] solution(String[] genres, int[] plays) {
        int N = genres.length;
        HashMap<String, Integer> playScore = new HashMap<>();
        HashMap<String, PriorityQueue<Integer>> playList = new HashMap<>();
        for(int i = 0 ; i < N; i++){
            playScore.put(genres[i], playScore.getOrDefault(genres[i], 0) + plays[i]);
            if(!playList.containsKey(genres[i])){
                playList.put(genres[i], new PriorityQueue<>((a, b)->{
                    return plays[b] - plays[a];
                }));
            }
            playList.get(genres[i]).add(i);
        }
        List<Genres> rank = new ArrayList<>();
        for(String x : playScore.keySet()){
            rank.add(new Genres(x, playScore.get(x)));
        }

        Collections.sort(rank);

        List<Integer> result = new ArrayList<>();
        for(Genres g: rank){
            String x = g.genre;
            // System.out.println(x + " " +playScore.get(x));
            if(playList.get(x).size() >= 2){
                result.add(playList.get(x).poll());
                result.add(playList.get(x).poll());
            }else if(playList.get(x).size() == 1){
                result.add(playList.get(x).poll());
            }
        }
        int[] answer = new int[result.size()];
        for(int i = 0 ; i < result.size(); i++){
            answer[i] = result.get(i);
        }
        return answer;
    }
}