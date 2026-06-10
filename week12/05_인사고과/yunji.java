import java.util.*;

class Solution {
    class Person implements Comparable<Person>{
        int id;
        int score1;
        int score2;

        public Person(int id, int score1, int score2){
            this.id = id;
            this.score1 = score1;
            this.score2 = score2;
        }

        public int compareTo(Person o){
            if(this.score1 == o.score1){
                return this.score2 - o.score2;
            }
            return o.score1 - this.score1;
        }
    }
    public int solution(int[][] scores) {
        int answer = 0;

        List<Person> list = new ArrayList<>();
        for(int i = 0 ; i <scores.length; i++){
            list.add(new Person(i, scores[i][0], scores[i][1]));
        }

        Collections.sort(list);

        int secondMax = list.get(0).score2;

        List<int []> scoreList = new ArrayList<>();
        scoreList.add(new int[]{list.get(0).id, list.get(0).score1 + list.get(0).score2});

        for(int i = 1 ; i < list.size(); i++){
            int currId = list.get(i).id;
            int currS1 = list.get(i).score1;
            int currS2 = list.get(i).score2;

            if(secondMax > currS2){

                if(currId == 0) return -1;
                secondMax = Math.max(secondMax, currS2);
                continue;

            }
            secondMax = Math.max(secondMax, currS2);
            scoreList.add(new int[]{currId, currS1+currS2});
        }

        Collections.sort(scoreList, (a,b)->{
            return b[1] - a[1];
        });

        int [] ranking = new int[scores.length];
        int rank = 1;
        int beforeScore = scoreList.get(0)[1];
        ranking[scoreList.get(0)[0]] = rank;

        for(int i = 1 ; i < scoreList.size(); i++){
            if(scoreList.get(i)[1] == beforeScore){
                ranking[scoreList.get(i)[0]] = rank;
            }else{
                rank = i+1;
                ranking[scoreList.get(i)[0]] = rank;
                beforeScore = scoreList.get(i)[1];
            }

        }


        answer = ranking[0];
        return answer;
    }
}