#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int t = 1;t <= T;t++) {
		int N, num;
		cin >> N;

		map<int, int>m;
		for (int i = 0;i < 1000;i++) {
			cin >> num;
			m[num]++;
		}

		int Max = 0, res = 0;
		for (auto it : m) {
			if (it.second >= Max) {
				res = it.first;
				Max = it.second;
			}
		}

		cout << "#" << t << " " << res << '\n';
	}

	return 0;
}

/*

		int Max = 0, res = 0;
		for (auto it : m) {
			if (it.second > Max) {
				res = it.first;
				Max = it.second;
			}
		}


		for (int i = 0;i < m.size();i++) {
			if (Max <= m[i]) {
				Max = m[i];
				res = i;
			}
		}

		왜 첫 번째가 위험하냐?

m[i]는 i번째 원소라는 뜻이 아니야.

m[i]

는

key가 i인 value

를 의미해.

예를 들어 map이 이렇게 들어있다고 하자.

m[3] = 10;
m[7] = 20;
m[15] = 5;

그러면 m.size()는 3이야.

첫 번째 코드는 이렇게 돈다.

i = 0 → m[0]
i = 1 → m[1]
i = 2 → m[2]

근데 실제 key는 3, 7, 15잖아?

그래서 m[3], m[7], m[15]는 아예 검사하지 못해.

더 문제는 m[0], m[1], m[2]가 없는데 m[i]를 쓰면, map이 자동으로 새 값을 만들어버려.

m[0] = 0;
m[1] = 0;
m[2] = 0;

이런 식으로 없는 key가 생김.

*/