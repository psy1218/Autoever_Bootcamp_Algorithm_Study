#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	string S, T;

	cin >> S >> T;

	//문자열 뒤에 A 제거
	//문자열 뒤에 B 제거하고 뒤집기
	
	// erase 사용하려면 위치, 개수 or 이터레이터로 해야함. 

	while (1) {
		if (S.size() == T.size()) {
			if (S == T) cout << 1 << '\n';
			if (S != T) cout << 0 << '\n';
			break;
		}

		if (*(T.end() - 1) == 'A') {
			T.erase(T.end() - 1);
		}

		else if (*(T.end() - 1) == 'B') { // else if 안 하고 if 하면 위에서  처리된게 또 돼. 
										  // S와 T의 길이가 각각 1, 2일 때 T가 0이 될 수가 있음. 그럼 무한 루프 걸릴 수 있음. 
			T.erase(T.end() - 1);
			reverse(T.begin(), T.end());
		}
	}


	return 0;
}

/*

	문자열 뒤에 A 추가
	문자열 뒤집고 뒤에 B 추가

	원래는 S를 T를 만들 수 있는지 생각했는데, -> 이러면 경우의 수를 다 생각해야함.
	근데 T를 S로 지우면서 만드는거지.

	문자열 뒤에 A 제거
	문자열 뒤에 B 제거하고 뒤집기 
*/

/*

원래는 S를 T를 만들 수 있는지 생각했는데, -> 이러면 경우의 수를 다 생각해야함.
근데 T를 S로 지우면서 만드는거지.

B
ABBA

BA 
-> A가 뒤에 있으면 무조건 지우기 가능
-> AB가 같이 있으면 A,B 다 지울 수 있음.
-> BA가 같이 있으면 A,B 다 지울 시 있음.
-> B가 뒤에 있으면 못 지움.

BAB
ABB

ABB

AABB

AB

AABB (o)

ABBA (o)

BAAB

AB  (o)

AAB (o)

BA
ABBA

BA
ABBA

BAAB
BAA
AAB
BAA

AB
BA
ABBA

AABB

BAA
AABB

BBB

BBB

*/

/*
S
B
ABA

B -> BA -> ABB

B -> BA -> ABB -> ABBA

B -> BB -> BBA -> BBAA 

B -> BA -> BAA -> AABB


무 일 경우
A 가 앞에 있기 위해서: A를 뒤에 붙이고 뒤집어야함.
B 가 앞에 있기 위해서: B를 뒤에 붙이고 뒤집어야함.
A 가 뒤에 있기 위해서: A를 그냥 붙이면 됨.
B 가 뒤에 있기 위해서: 뒤집고 B를 붙여야 함. 

뒤집으면 다 뒤집히는데...? 

BA ABBA

B -> BB -> BBA -> 

ABBBA


*/