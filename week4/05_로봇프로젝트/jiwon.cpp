#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std; 

int x,n;
vector<int> v;
int mx, l1, l2;

int main(){
    while(cin>>x>>n){
        v.clear();
        mx=-1;
        l1=0; l2=0;
        for(int i=0; i<n; i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        int l=0;
        int r=n-1;
        int ans=x*10000000;
        while(l<r){
            if(v[l]+v[r]==ans && v[r]-v[l]>mx){
                mx=v[r]-v[l];
                l1=v[l];
                l2=v[r];
                break;
            }
            else if (v[l]+v[r]<ans) l++;
            else if (v[l]+v[r]>ans) r--;
        }
        if(mx>=0){
            cout<<"yes "<<l1<<' '<<l2<<'\n';
        }
        else{
            cout<<"danger"<<'\n';
        }
    }
}