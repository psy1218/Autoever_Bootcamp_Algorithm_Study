//1244.cpp - 최대 상금


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
using namespace std;

int T, num, k;
int Max = 0;

// visited[교환횟수] = 그 횟수에서 이미 만들어본 숫자 상태들
set<string> visited[11]; // 11인 이유가 교환 횟수가 0 부터 11이기 떄문

void dfs(string cur, int cnt) {
	if (cnt >= k) {
		Max = max(Max, stoi(cur));
		return;
	}

	for (int i = 0; i < cur.size()-1; i++) {
		for (int j = i+1; j < cur.size(); j++) {

			string next = cur;
		
			char temp = next[i];
			next[i] = next[j];
			next[j] = temp;

			// cnt + 1번 교환해서 next 상태를 이미 만든 적 있으면 생략
			if (visited[cnt + 1].find(next) != visited[cnt + 1].end()) continue;

			visited[cnt + 1].insert(next);
			dfs(next, cnt+1);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> num >> k;

		string Num = to_string(num);
		Max = 0;

		for (int i = 0; i <= 10; i++) {
			visited[i].clear();
		}

		visited[0].insert(Num);

		dfs(Num, 0);

		cout << "#" << t << " " << Max << "\n";
	}

	return 0;
}

/*
0번 교환:
123

1번 교환:
213, 321, 132

2번 교환:
123, 312, 231

3번 교환:
213, 321, 132

4번 교환:
123, 312, 231


방문 체크 = "몇 번 교환해서 이 숫자 상태를 이미 만들어봤는지" 기록하는 것
같은 교환 횟수에서 같은 숫자 상태가 여러 경로로 계속 반복해서 나오기 때문
*/

/*
10
123 1
2737 1
757148 1
78466 2
32888 2
777770 5
436659 2
431159 7
112233 3
456789 10

#1 321
#2 7732
#3 857147
#4 87664
#5 88832
#6 777770
#7 966354
#8 954311
#9 332211
#10 987645

*/

# if 0
#include <iostream>
#include <string>
using namespace std;

int money(int num, int change){
    string str_num = to_string(num); // [ 3 2 8 8 8 ]
    int num_len = str_num.length();
    int max_v = 0, max_index = 0;
    if(num_len == 2){
        if(change % 2 == 0){
            return num;
        }
        else{
            int temp = int(str_num[0]);
            str_num[0] = str_num[1];
            str_num[1] = temp;
            return stoi(str_num); 
        }
    }

    for(int i=0;i<num_len; i++){
        if(max_v <= str_num[i]){
            max_v = str_num[i];   
            max_index = i;
        }
    }
    while (1){

    }
}

int main(){
    int T, num, change;
    cin >> T;
    int res = 0;
    for(int i=1;i<=T;i++){
        cin >> num >> change;
        res = money(num, change);
        cout << '#' << i << ' ' << res << '/n';
    }
    return 0;
}
#endif 
/*
123 
12 + 3
1 + 2 + 3
*/