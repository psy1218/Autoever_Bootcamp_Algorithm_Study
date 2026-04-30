#include <iostream>
#include <map>
using namespace std;
// 차이가 가장 크다는 것은 가장 큰 수와 가장 작은 수가 차이가 가장 큼.
// 정렬 이용 - map 사용함 

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x;
	while (cin >> x) { // 여러 테스트 케이스
        int target = x * 10000000;  // cm → nm 변환

		int n, len;
		cin >> n;

		map<int, int>cnt;
		for (int i = 0; i < n; i++) {
			cin >> len;
			cnt[len]++;
		}

        bool found = false;

        // 가장 큰 값부터 확인
        for (auto it = cnt.rbegin(); it != cnt.rend(); ++it) {
            int l1 = it->first; // 큰 조각
            int l2 = target - l1; // 작은 조각 

            if (l2 < 0) continue;  // 음수는 불가능 = 구멍보다 조각이 큰 경우 

            auto f = cnt.find(l2);
            if (f == cnt.end()) continue;  // 필요한 값 없음

            // 같은 값이면 두 개 이상 있어야 함 - 무조건 2개 이상 
            if (l1 == l2 && f->second < 2) continue; // 없으면 continue 

            cout << "yes " << min(l1, l2) << " " << max(l1, l2) << "\n";
            found = true;
            break;  // 첫 성공이 차이 최대
        }

        if (!found) {
            cout << "danger\n";
        }
	
	}

	return 0;
}