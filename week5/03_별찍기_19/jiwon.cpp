#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 

int N;
char a[400][400];

void star(int n, int x, int y){
    if(n==0) return;
    int len=4*n-3;
    for(int i=x; i<x+len; i++){
        a[x][i]='*';
        a[x+len-1][i]='*';
    }
    for(int i=y; i<y+len; i++){
        a[i][y]='*';
        a[i][y+len-1]='*';
    }
    star(n-1, x+2, y+2);
}

int main(){
    cin>>N;
    int l=4*N-3;
    for(int i=0; i<l; i++){
        for(int j=0; j<l; j++){
            a[i][j]=' ';
        }
    }
    star(N,0,0);
        for(int i=0; i<l; i++){
        for(int j=0; j<l; j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}