#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt", "r", stdin);


	for (int t = 1; t <= 10; t++) {
		int N;
		cin >> N;
		string str;
		cin >> str;
		char c;
		stack<int>s;
		int res = 1;
		for (int i = 0; i < N; i++) {
			c = str[i];
			if (c == '{' || c == '<' || c == '[' || c == '(') s.push(c);
			else {
				if (s.empty()) {
					res = 0;
					break;
				}

				if (c == '}' && s.top() != '{') {
					res = 0;
					break;
				}
				if (c == ']' && s.top() != '[') {
					res = 0;
					break;
				}
				if (c == '>' && s.top() != '<') {
					res = 0;
					break;
				}
				if (c == ')' && s.top() != '(') {
					res = 0;
					break;
				}



				s.pop();
			}
		}

		if (!s.empty()) res = 0;

		cout << "#" << t << " " << res << '\n';

	}

	return 0;
}
/*
* 
* 문제 이해 잘 못 함. 그냥 개수 맞으면 되는 줄 알았는데 최근 열린게 괄호가 지금 닫혔는지 문제임.
* {[}] 이것도 틀림. 짝이 맞아야함.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt", "r", stdin);


	for (int t = 1; t <= 10; t++) {
		int N;
		cin >> N;
		string str;
		cin >> str;

		vector<int>Data(4, 0);

		int res = 1;

		int flag1 = 0, flag2 = 0, flag3 = 0, flag = 4;
		for (int i = 0; t < str.size(); i++){
			if (str[i] == '(') {
				if(flag == 0) Data[0]++;
				if (flag == 1) res = 0;
			}
			if (str[i] == ')') {
				if (flag == 0) {
					Data[0]--;
					flag = 1;
				}
				if (Data[0] == 0) flag = 0;
			}
		}
	}


	return 0;
}
*/

/*
230
[({([<[<[<<(([{([<((({<{([{[<[<<<([<[<([[{([<[{({([<(<[[][]]<>{}<>[]>){}{}<>>]{}())})}[]]{}>[][][]]()[][]<><>()<>){}}]])[][][]>]>()](){}[])>>><><>{}]>]{}[]}<>][]())}[][]>}<>)()))>{}[]()])[][]}]<>()<>))>>()][]>][][]>]())}<><>{}<>)]


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt", "r", stdin);


	for (int t = 1; t <= 3; t++) {
		int N;
		cin >> N;
		string str;
		cin >> str;

		vector<int>visited(8, 0);

		int res = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' ){
				if (visited[0] == 0) {
					visited[0] = 1;
				}
				else break;
			}
			if (str[i] == ')') {
				if (visited[1] == 0) {
					visited[1] = 1;
				}
				else break;

				if (visited[0] == 1) {
					visited[0] = 0;
					visited[1] = 0;
				}
			}

			if (str[i] == '[') {
				if (visited[2] == 0) {
					visited[2] = 1;
				}
				else break;
			}
			if (str[i] == ']') {
				if (visited[3] == 0) {
					visited[3] = 1;
				}
				else break;

				if (visited[2] == 1) {
					visited[2] = 0;
					visited[3] = 0;
				}
			}

			if (str[i] == '{') {
				if (visited[4] == 0) {
					visited[4] = 1;
				}
				else break;
			}
			if (str[i] == '}') {
				if (visited[5] == 0) {
					visited[5] = 1;
				}
				else break;

				if (visited[4] == 1) {
					visited[4] = 0;
					visited[5] = 0;
				}
			}

			if (str[i] == '<') {
				if (visited[6] == 0) {
					visited[6] = 1;
				}
				else break;
			}
			if (str[i] == '>') {
				if (visited[7] == 0) {
					visited[7] = 1;
				}
				else break;

				if (visited[6] == 1) {
					visited[6] = 0;
					visited[7] = 0;
				}
			}
		}

		int flag = 1;
		for (int i = 0; i < 8; i += 2) {
			if (visited[i] != visited[i + 1]) {
				flag = 0;
				break;
			}
		}

		if (flag == 0) res = 0;
		else res = 1;

		cout << "#" << t << ' ' << res << '\n';
	}

	return 0;
}
*/

/*
16
{[()]}<>[<{}><>]
16
{[()]}<>[<{}><>[
16
{[()]}<>[<{)><>]




*/
