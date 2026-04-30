#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[100001] = { 0, };
	arr[1] = -1;
	arr[2] = 1;
	arr[3] = -1;
	arr[4] = 2;
	arr[5] = 1;

	for (int i = 6; i < 100001; i++) {
		int temp = i;

		if (temp / 5 < 2) { // 10 이하는 조합되기에는 수도 작고, 6과 8은 5로 뺏을 때 1과 3이 남아서 2로만 처리해야함.
			if (temp % 5 == 1 || temp % 5 == 3) {
				arr[i] = arr[temp - 2] + 1;
				continue;
			}
		}

		arr[i] = arr[temp - 5] + arr[5];
	}

	cout << arr[n]<<'\n';
	return 0;
}

/*

13 - 2*3+5
10 - 2*5


 1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20
-1  1 -1  2  1  3  2  4  3   2   4   3   5



		if (temp / 5 < 1) {
			if (temp % 5 == 1 || temp % 5 == 3) {
				arr[i] = arr[temp - 2] + 1;
			}
		}
*/