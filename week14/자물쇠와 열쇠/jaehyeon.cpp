#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> turn(vector<vector<int>> key)
{
    int n = key.size();
    vector<vector<int>> ret(n, vector<int>(n, 0));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            ret[j][n-i-1] = key[i][j];
        }
    }
    
    return ret;
}

bool check(vector<vector<int>>& board, int n)
{
    for(int i=n; i<n*2; i++)
    {
        for(int j=n; j<n*2; j++)
        {
            if(board[i][j] != 1) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key.size();
    int n = lock.size();
    
    vector<vector<int>> board(n*3, vector<int>(n*3, 0));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            board[n+i][n+j] = lock[i][j];
        }
    }
    
    for(int r=0; r<4; r++)
    {
        for(int x=0; x<n*2; x++)
        {
            for(int y=0; y<n*2; y++)
            {
                for(int i=0; i<m; i++)
                {
                    for(int j=0; j<m; j++)
                    {
                        board[x+i][y+j] += key[i][j];
                    }
                }
                
                if(check(board, n)) return true;
                
                for(int i=0; i<m; i++)
                {
                    for(int j=0; j<m; j++)
                    {
                        board[x+i][y+j] -= key[i][j];
                    }
                }
            }
        }
        
        key = turn(key);
    }
    
    return false;
}