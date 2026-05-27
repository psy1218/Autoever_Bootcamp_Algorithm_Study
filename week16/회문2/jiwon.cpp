#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T;
char board[100][100];

bool check(const string& s){
    int l=0;
    int r=s.length()-1;
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
int main(){
    while(cin>>T){
        int ans=1;
        for(int i=0; i<100; i++){
            string s;
            cin>>s;
            for(int j=0; j<100; j++){
                board[i][j]=s[j];
            }
        }
        for(int len=100; len>1; len--){
            if(len<=ans)break;
            for(int i=0; i<100; i++){
                for(int j=0; j<=100-len; j++){
                    string row_str="";
                    string col_str="";
                    for(int k=0; k<len; k++){
                        row_str+=board[i][j+k];
                        col_str+=board[j+k][i];
                    }
                    if(check(row_str) || check(col_str)){
                        ans=max(ans,len);
                    }
                }
            }
        }
        cout<<'#'<<T<<' '<<ans<<'\n';
    }
    return 0;
}