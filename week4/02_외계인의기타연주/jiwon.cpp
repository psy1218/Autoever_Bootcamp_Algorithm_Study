#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std; 

int N,P,now,cnt;
vector<int> s[7];

int main(){
    cin>>N>>P;
    for(int i=0; i<N; i++){
        int j,p;
        cin>>j>>p;

        if(!s[j].empty()){
            while(!s[j].empty()){
                if(p>s[j].back()){ //원래보다 높은 경우
                    s[j].push_back(p);
                    cnt++;
                    break;
                }
                else if(p==s[j].back()){
                    break;
                }
                else {
                    s[j].pop_back();
                    cnt++;
                }
            }
        }
        if(s[j].empty()){
            s[j].push_back(p);
            cnt++;
        }
    }
    cout<<cnt;
}