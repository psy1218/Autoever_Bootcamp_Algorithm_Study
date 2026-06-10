#include <string>
#include <vector>

using namespace std;

bool pass(int num, vector<int>& stones, int k){
    int cnt=0;
    for(int i=0; i<stones.size(); i++){
        if(stones[i]<num){
            cnt++;
            if(cnt>=k) return false;
        }
        else{
            cnt=0;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left=1;
    int right=200000000;
    while(left<=right){
        int mid=(left+right)/2;
        if(pass(mid,stones,k)){
            answer=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return answer;
}