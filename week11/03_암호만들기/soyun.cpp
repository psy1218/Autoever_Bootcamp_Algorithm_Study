#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int L, C;
vector<char>List;
vector<char>Data;


void dfs(int cnt, int start, int M, int J) {
	if (cnt >= L) {
		if (M >= 1 && J >= 2) {
			for (int k = 0;k < L;k++) {
				cout << Data[k];
			}
			cout << '\n';
		}
		return;
	}

	for (int i = start;i < C;i++) {
		if (!Data.empty() && Data[Data.size() - 1] >= List[i]) continue;

		if (List[i] == 'a' || List[i] == 'e' || List[i] == 'i' || List[i] == 'o' || List[i] == 'u') M++;
		else J++;

		Data.push_back(List[i]);
		dfs(cnt + 1, start + 1, M, J);
		if (Data[Data.size() - 1] == 'a' || Data[Data.size() - 1] == 'e' || Data[Data.size() - 1] == 'i' || Data[Data.size() - 1] == 'o' || Data[Data.size() - 1] == 'u') M--;
		else J--;
		Data.pop_back();
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	char c;
	cin >> L >> C;

	for (int i = 0;i < C;i++) {
		cin >> c;
		List.push_back(c);
	}

	sort(List.begin(), List.end());
	
	dfs(0, 0, 0, 0);
	return 0;
}


/*
a c i s t w

acis
acit
aciw
acst
acsw
actw
aist
aisw
aitw
astw
c
*/