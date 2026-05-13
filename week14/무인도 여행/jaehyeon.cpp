#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int mx[4]={-1,1,0,0};
int my[4]={0,0,-1,1};

vector<int> solution(vector<string> maps) {
    
    vector<int> answer;
    
    int n=maps.size();
    int m=maps[0].size();
    
    vector<vector<int>> visit(n, vector<int>(m,0));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(maps[i][j]=='X' || visit[i][j]) continue;
            
            queue<pair<int,int>> q;
            q.push({i,j});
            visit[i][j]=1;
            
            int food=0;
            
            while(!q.empty())
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                
                food+=maps[x][y]-'0';
                
                for(int k=0; k<4; k++)
                {
                    int nx=x+mx[k];
                    int ny=y+my[k];
                    
                    if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                    if(visit[nx][ny]) continue;
                    if(maps[nx][ny]=='X') continue;
                    
                    visit[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
            
            answer.push_back(food);
        }
    }
    
    if(answer.size()==0) return {-1};
    
    sort(answer.begin(), answer.end());
    
    return answer;
}