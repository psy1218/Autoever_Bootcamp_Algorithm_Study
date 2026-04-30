#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

long long N, Count = 0, Min = LLONG_MAX;
vector<pair<long long, long long>>input;
vector<pair<long long, long long>>Data;


void calculator() {
	int a = 1, b = 0;
	for (int i = 0; i < Data.size(); i++) {
		a *= Data[i].first;
		b += Data[i].second;
	}

	if (Min > abs(a - b)) {
		Min = abs(a - b);
	}
}

void dfs(int start) {

	for (int i = start; i < N; i++) {
		Data.push_back({ input[i].first,input[i].second });
		calculator();
		dfs(i + 1);
		Data.pop_back();
	}
}

int main() {
	cin >> N;

	long long S, B;
	for (int i = 0; i < N; i++) {
		cin >> S >> B;
		input.push_back({ S,B });
	}

	dfs(0);

	cout << Min << '\n';

	return 0;
}