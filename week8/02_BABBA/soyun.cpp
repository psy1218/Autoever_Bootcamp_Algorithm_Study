#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<pair<int, int>>v;

	v.push_back({ 1,0 });
	v.push_back({ 0,1 });

	for (int i = 2; i < 46; i++) {
		int a = v[i - 1].first + v[i - 1].second;
		int b = v[i - 1].second;
		v.push_back({ b,a });
	}

	int K;
	cin >> K;

	cout << v[K].first << " " << v[K].second << '\n';

	return 0;
}

/*
A B BA BAB BABBA BABBAB BABBABBA BABBABBAB BABBABBABBA BABBABBABBAB BABBABBABBABBA
이거 아님 
상근이는 화면의 모든 B는 BA로 바뀌고, A는 B로 바뀐다는 사실을 알게되었다.

A                     1 0 - 0
B                     0 1 - 1
BA                    1 1
BAB                   1 2
BABBA                 2 3
BABBABAB              3 5
BABBABABBABBA         5 8
BABBABABBABBABBABAB
*/