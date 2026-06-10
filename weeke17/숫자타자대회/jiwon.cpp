#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int INF=1e9;
int cost[10][10];
int dp[10][10];
int next_dp[10][10];
pair<int,int> pos[10]={{3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
void init_cost(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i==j){
                cost[i][j]=1;
                continue;
            }
            int dy=abs(pos[i].first-pos[j].first);
            int dx=abs(pos[i].second-pos[j].second);
            int diag=min(dy,dx);
            int str=max(dy,dx)-diag;
            cost[i][j]=diag*3+str*2;
        }
    }
}
int solution(string numbers){
    init_cost();
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            dp[i][j]=INF;
        }
    }
    dp[4][6]=0;
    for(char ch:numbers){
        int target=ch-'0';
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                next_dp[i][j]=INF;
            }
        }
        for(int l=0;l<10;l++){
            for(int r=0;r<10;r++){
                if(dp[l][r]==INF)continue;
                if(l==r)continue;
                if(target!=r){
                    next_dp[target][r]=min(next_dp[target][r],dp[l][r]+cost[l][target]);
                }
                if(target!=l){
                    next_dp[l][target]=min(next_dp[l][target],dp[l][r]+cost[r][target]);
                }
            }
        }
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                dp[i][j]=next_dp[i][j];
            }
        }
    }
    int ans=INF;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            ans=min(ans,dp[i][j]);
        }
    }
    return ans;
}
