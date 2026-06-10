#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF=1e9;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
struct Point{int r,c,d;};
int bfs(vector<vector<int>>& board,int src_r,int src_c,int dst_r,int dst_c){
    if(src_r==dst_r&&src_c==dst_c)return 0;
    queue<Point> q;
    bool visited[4][4]={false};
    q.push({src_r,src_c,0});
    visited[src_r][src_c]=true;
    while(!q.empty()){
        Point cur=q.front();
        q.pop();
        if(cur.r==dst_r&&cur.c==dst_c)return cur.d;
        for(int i=0;i<4;i++){
            int nr=cur.r+dr[i];
            int nc=cur.c+dc[i];
            if(nr>=0&&nr<4&&nc>=0&&nc<4){
                if(!visited[nr][nc]){
                    visited[nr][nc]=true;
                    q.push({nr,nc,cur.d+1});
                }
            }
            nr=cur.r;
            nc=cur.c;
            while(true){
                int nnr=nr+dr[i];
                int nnc=nc+dc[i];
                if(nnr<0||nnr>=4||nnc<0||nnc>=4)break;
                nr=nnr;
                nc=nnc;
                if(board[nr][nc]!=0)break;
            }
            if(!visited[nr][nc]){
                visited[nr][nc]=true;
                q.push({nr,nc,cur.d+1});
            }
        }
    }
    return 0;
}
int match_cards(vector<vector<int>> board,vector<pair<int,int>> cards[],vector<int>& order,int r,int c){
    int total_dist=0;
    int cur_r=r,cur_c=c;
    for(int card_num:order){
        int p1_r=cards[card_num][0].first,p1_c=cards[card_num][0].second;
        int p2_r=cards[card_num][1].first,p2_c=cards[card_num][1].second;
        int d1=bfs(board,cur_r,cur_c,p1_r,p1_c)+bfs(board,p1_r,p1_c,p2_r,p2_c);
        int d2=bfs(board,cur_r,cur_c,p2_r,p2_c)+bfs(board,p2_r,p2_c,p1_r,p1_c);
        if(d1<d2){
            total_dist+=d1;
            cur_r=p2_r;cur_c=p2_c;
        }else{
            total_dist+=d2;
            cur_r=p1_r;cur_c=p1_c;
        }
        total_dist+=2;
        board[p1_r][p1_c]=0;
        board[p2_r][p2_c]=0;
    }
    return total_dist;
}
int solution(vector<vector<int>> board,int r,int c){
    int ans=INF;
    vector<pair<int,int>> cards[7];
    vector<int> order;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(board[i][j]!=0){
                cards[board[i][j]].push_back({i,j});
                if(find(order.begin(),order.end(),board[i][j])==order.end()){
                    order.push_back(board[i][j]);
                }
            }
        }
    }
    sort(order.begin(),order.end());
    do{
        vector<int> current_order=order;
        int card_count=order.size();
        for(int i=0;i<(1<<card_count);i++){
            vector<vector<int>> temp_board=board;
            int total_dist=0;
            int cur_r=r,cur_c=c;
            for(int j=0;j<card_count;j++){
                int card_num=current_order[j];
                int first_idx=(i&(1<<j))?1:0;
                int second_idx=1-first_idx;
                int p1_r=cards[card_num][first_idx].first,p1_c=cards[card_num][first_idx].second;
                int p2_r=cards[card_num][second_idx].first,p2_c=cards[card_num][second_idx].second;
                total_dist+=bfs(temp_board,cur_r,cur_c,p1_r,p1_c);
                total_dist+=bfs(temp_board,p1_r,p1_c,p2_r,p2_c);
                total_dist+=2;
                temp_board[p1_r][p1_c]=0;
                temp_board[p2_r][p2_c]=0;
                cur_r=p2_r;cur_c=p2_c;
            }
            ans=min(ans,total_dist);
        }
    }while(next_permutation(order.begin(),order.end()));
    return ans;
}
