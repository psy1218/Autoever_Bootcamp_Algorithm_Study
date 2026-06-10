#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int N;
vector<int>Data;
bool output = false;

bool decimal(int num) {

	if (num < 2) return false;

	for (int i = 2;i <= sqrt(num);i++) { // 헤더파일 algorithm 이 아니라 cmath 임.
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

bool check(vector<int>& Data) {
	string str;
	for (int i = 1;i <= N;i++) {
		str.clear();
		for (int j = 0;j < i;j++) {
			str.push_back(Data[j] + '0'); // 만약 Data[j] 가 2일 때, 숫자 2가 str에 들어가는게 아님.
									// 아스키 코드 2가 들어가는거임. '0' 더해줘야 숫자 2가 들어감. 
		}

		int num = stoi(str);
		if (decimal(num) == false) return false;
	}

	return true;
}


void dfs(int cnt) {
	if (cnt >= N) {

		output = check(Data);

		if (output == false) return;

		for (int k = 0;k < N;k++) {
			cout << Data[k];
		}
		cout << '\n';

		return;
	}

	for (int i = 1; i <= 9;i++) {
		Data.push_back(i);
		dfs(cnt + 1);
		Data.pop_back();
	}
}

int main() {
	cin >> N;
	
	dfs(0);

	return 0;
}