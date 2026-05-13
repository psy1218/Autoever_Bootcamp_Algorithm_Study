#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 

priority_queue<int> pq;
int N,cost;


int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
    cin>>N;
    for(int i=0; i<N; i++){
        int c;
        cin>>c;
        pq.push(c);
    }
    for(int i=0; i<N/3; i++){
        cost+=pq.top();
        pq.pop();
        cost+=pq.top();
        pq.pop();
        pq.pop();
    }
    for(int i=0; i<N%3; i++){
        cost+=pq.top();
        pq.pop();
    }
    cout<<cost;
}