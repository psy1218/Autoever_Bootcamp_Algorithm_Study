#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(int distance,vector<int> rocks,int n){
    int ans=0;
    sort(rocks.begin(),rocks.end());
    int l=1,r=distance;
    while(l<=r){
        int mid=l+(r-l)/2;
        int remove_cnt=0;
        int prev=0;
        for(int i=0;i<rocks.size();i++){
            if(rocks[i]-prev<mid){
                remove_cnt++;
            }else{
                prev=rocks[i];
            }
        }
        if(distance-prev<mid){
            remove_cnt++;
        }
        if(remove_cnt<=n){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans;
}
