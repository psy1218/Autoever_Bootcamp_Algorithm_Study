#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 

int N, st, ba, cnt;
bool list[999];

void numbers(){
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            if(i==j) continue;
            for(int k=1; k<=9; k++){
                if(i==k || j==k) continue;
                list[i*100+j*10+k]=true;
            }
        }
    }
}

int main() { 
    cin>>N;
    numbers();
    for(int i=0; i<N; i++){
        int num;
        int s,b;
        cin>>num>>s>>b;
        for(int j=123; j<999; j++){
            st=0; ba=0;
            if(list[j]==true){
                if(num/100 == j/100) st++;
                else if(num/100 == (j%100)/10) ba++;
                else if(num/100 == j%10) ba++;

                if((num%100)/10 == j/100) ba++;
                else if((num%100)/10 == (j%100)/10) st++;
                else if((num%100)/10 == j%10) ba++;

                if(num%10 == j/100) ba++;
                else if(num%10 == (j%100)/10) ba++;
                else if(num%10 == j%10) st++;
                
                if(s!=st || b!=ba){
                    list[j]=false;
                    // cout<<j<<endl;
                }
            }
        }
    }
    for(int j=123; j<999; j++){
        if(list[j]==true){
            cnt++;
        }
    }
    cout<<cnt;
}