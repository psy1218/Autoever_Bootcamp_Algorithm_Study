#include <string>
#include <vector>

using namespace std;
int n,m;

vector<vector<int>> rotate(vector<vector<int>> key) {
    int m = key.size();
    vector<vector<int>> result(m, vector<int>(m));
    for (int r=0; r<m; r++) {
        for (int c=0; c<m; c++) {
            result[c][m-1-r] = key[r][c];
        }
    }
    return result;
}

bool check(vector<vector<int>>& lock){ 
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if(lock[m-1+i][m-1+j]!=1){
                return false;
            }
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    n=lock.size();
    m=key.size();
        
    int new_size=n+2*(m-1);
    vector<vector<int>> new_lock(new_size, vector<int>(new_size, 0));
    
    // 중앙에 배치
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            new_lock[m-1+i][m-1+j]=lock[i][j];
        }
    }
    
    for(int dir=0; dir<4; dir++){
        key=rotate(key);
        for (int x=0; x<n+m-1; x++) {
            for (int y=0; y<n+m-1; y++) {
                
                // 자물쇠에 열쇠 끼우기
                for (int i=0; i<m; i++) {
                    for (int j=0; j<m; j++) {
                        new_lock[x+i][y+j] += key[i][j];
                    }
                }

                if (check(new_lock)) return true;

                // 열쇠 다시 빼기
                for (int i=0; i<m; i++) {
                    for (int j=0; j<m; j++) {
                        new_lock[x+i][y+j] -= key[i][j];
                    }
                }
            }
        }
    }
    return false;
}