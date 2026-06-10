#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<pair<int,int>> card[7];

int bfs(vector<vector<int>> board, int sx, int sy, int ex, int ey)
{
    queue<pair<int,int>> q;
    int dist[4][4];

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            dist[i][j]=-1;

    q.push({sx,sy});
    dist[sx][sy]=0;

    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        if(x==ex && y==ey)
            return dist[x][y];

        for(int d=0;d<4;d++)
        {
            int nx=x+dx[d];
            int ny=y+dy[d];

            if(nx>=0 && nx<4 && ny>=0 && ny<4 && dist[nx][ny]==-1)
            {
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }

            nx=x;
            ny=y;

            while(true)
            {
                int tx=nx+dx[d];
                int ty=ny+dy[d];

                if(tx<0 || tx>=4 || ty<0 || ty>=4)
                    break;

                nx=tx;
                ny=ty;

                if(board[nx][ny]!=0)
                    break;
            }

            if(dist[nx][ny]==-1)
            {
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }
    }

    return 0;
}

int dfs(vector<vector<int>> board, int x, int y, vector<int> order, int idx)
{
    if(idx==order.size())
        return 0;

    int num=order[idx];

    int x1=card[num][0].first;
    int y1=card[num][0].second;

    int x2=card[num][1].first;
    int y2=card[num][1].second;

    int res=1e9;

    {
        auto temp=board;

        int a=bfs(temp,x,y,x1,y1);

        temp[x1][y1]=0;

        int b=bfs(temp,x1,y1,x2,y2);

        temp[x2][y2]=0;

        res=min(res,a+b+2+
            dfs(temp,x2,y2,order,idx+1));
    }

    {
        auto temp=board;

        int a=bfs(temp,x,y,x2,y2);

        temp[x2][y2]=0;

        int b=bfs(temp,x2,y2,x1,y1);

        temp[x1][y1]=0;

        res=min(res,a+b+2+
            dfs(temp,x1,y1,order,idx+1));
    }

    return res;
}

int solution(vector<vector<int>> board, int r, int c)
{
    for(int i=1;i<=6;i++)
        card[i].clear();

    vector<int> nums;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(board[i][j])
            {
                card[board[i][j]].push_back({i,j});
            }
        }
    }

    for(int i=1;i<=6;i++)
    {
        if(!card[i].empty())
            nums.push_back(i);
    }

    int answer=1e9;

    sort(nums.begin(),nums.end());

    do
    {
        answer=min(answer,
            dfs(board,r,c,nums,0));

    } while(next_permutation(nums.begin(),nums.end()));

    return answer;
}