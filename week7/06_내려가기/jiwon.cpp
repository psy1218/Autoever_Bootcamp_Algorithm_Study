#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 

int N;
int a[3];
int dpmax[3], dpmin[3];
int nextmax[3], nextmin[3];

int main(){
    cin>>N;
    for(int i=0; i<3; i++){
        int b;
        cin>>b;
        dpmax[i]=b;
        dpmin[i]=b;
    }
    for(int i=1; i<N; i++){
        for(int j=0; j<3; j++){
            cin>>a[j];
        }
        nextmax[0]=a[0]+max(dpmax[0],dpmax[1]);
        nextmax[1]=a[1]+max({dpmax[0],dpmax[1],dpmax[2]});
        nextmax[2]=a[2]+max(dpmax[1],dpmax[2]);

        nextmin[0]=a[0]+min(dpmin[0],dpmin[1]);
        nextmin[1]=a[1]+min({dpmin[0],dpmin[1],dpmin[2]});
        nextmin[2]=a[2]+min(dpmin[1],dpmin[2]);

        for(int i=0; i<3; i++){
            dpmax[i]=nextmax[i];
            dpmin[i]=nextmin[i];
        }
    }

    cout<<max({dpmax[0],dpmax[1],dpmax[2]})<<' '<<min({dpmin[0],dpmin[1],dpmin[2]});
}