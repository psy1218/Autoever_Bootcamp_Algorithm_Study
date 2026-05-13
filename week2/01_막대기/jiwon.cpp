#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int cnt;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int X; 
	cin>>X;
	for(int i=0; i<=6; i++){
		if(X&1<<(i)){
			cnt++;
		}
	}
	cout<<cnt;
}
