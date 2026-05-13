#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 

int n, ans;

int main(){
    cin>>n;
    int a=n/5;
    int b=n%5;
    if(n==1 || n==3){
        cout<<-1;
        exit(0);
    }
    else if (b%2==0){
        ans=a+b/2;
    }
    else{
        ans=a-1+(b+5)/2;
    }
    cout<<ans;
}