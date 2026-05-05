#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int a[130][130];
int white, blue;

void count(int n, int x, int y){
    // cout<<x<<' '<<y<<endl;
    int b=1, w=0;
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if((b&a[i][j])==1){
                w=1;
            }
            else if((w|a[i][j])==0){
                b=0;
            }
            else{
                for(int i=0; i<4; i++){
                    count(n/2, x+(n/2)*(i/2), y+(n/2)*(i%2)); // 00 01 10 11 
                }
                return;
            }
        }
    }
    if(b==1){
        blue++;
    }
    else if(w==0){
        white++;
    }
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>a[i][j];
        }
    }
    count(N,0,0);
    cout<<white<<'\n'<<blue;
}