#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;



int main() {

	long long T, n, m, num;
	vector<long long>A;
	vector<long long>B;
	cin >> T >> n;
	for (int i = 0;i < n;i++) {
		cin >> num;
		A.push_back(num);
	}
	cin >> m;
	for (int i = 0;i < m;i++) {
		cin >> num;
		B.push_back(num);
	}

	vector<long long>sum_A;
	for (int i = 0;i < n;i++) {
		long long sum = 0;
		for (int j = i;j < n;j++) {
			sum += A[j]; // A에 대해 모든 부분 배열 합 구하기
			sum_A.push_back(sum);
		}
	}

	vector<long long>sum_B;
	for (int i = 0;i < m;i++) {
		long long sum = 0;
		for (int j = i;j < m;j++) {
			sum += B[j]; // B에 대해 모든 부분 배열 합 구하기
			sum_B.push_back(sum);
		}
	}
	

	//sort(sum_A.begin(), sum_A.end());

	map<long long, long long>cnt;
	for (long long x : sum_B) {
		cnt[x]++; // 개수 몇 개인지 파악하기 
	}

	long long ans = 0;
	for (int i = 0;i < sum_A.size();i++) {
		//if (sum_A[i] >= T) break; // 음수도 있음. 
		ans += cnt[T - sum_A[i]];
	}

	// 원래는 find 함수 이용해서, 실제로 하나하나 T  빼기 이용해서 쓰려고 했는데 시간 오래 걸림.
	//for (int i = 0;i < sum_A.size();i++) {
	//	if (sum_A[i] >= T) break;
	//	if (find(sum_B.begin(), sum_B.end(), T - sum_A[i])) {
	//	
	//	}
	//}


	cout << ans << '\n';

	return 0;
}
/*
1) A의 모든 부분배열 합 구하기
2) B의 모든 부분배열 합도 구하기
3) 한쪽을 정렬하고, 다른 쪽에서 필요한 값을 찾기 - map 이용하기 
*/