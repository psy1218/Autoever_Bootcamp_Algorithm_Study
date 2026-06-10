#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int N, K, num;
	cin >> N >> K;

	vector<int>tall;
	vector<int>diff;

	for (int i = 0; i < N; i++) {
		cin >> num;
		tall.push_back(num);
	}

	sort(tall.begin(), tall.end());

	for (int i = 0; i < N-1; i++) {
		diff.push_back(tall[i + 1] - tall[i]);
	}

	sort(diff.begin(), diff.end());

	int res = 0;
	for (int i = 0; i < N-K; i++) { // 총 인원수 - 조 수 = 5 인원에 3개 조 하려면 2개로 나뉘어야함. 
		res += diff[i];// 비용이 큰 값은 빼고 작은 것만 계산 
	}

	cout << res << '\n';

	return 0;
}

// diff = N-1 , 조가 k면 k-1 잘라야하니까 => 자르고 남는게 최소 개수 = N-1-K+1 N - K