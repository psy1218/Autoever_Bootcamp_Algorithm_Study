#include <iostream>
#include <unordered_map>

using namespace std;

int T,t,score;

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin>>t;
		int ans=0;
		int mx=-1;
		unordered_map<int,int> mp;
		for(int j=0; j<1000; j++){
			cin>>score;
			mp[score]++;
		}
		for(int j=0; j<=100; j++){
			if(mx<=mp[j]){
				mx=mp[j];
				ans=j;
			}
		}
		cout << '#' << t << ' ' << ans << '\n';
	}
	return 0;
}