/*
=> 3으로 나눴을 때의 몫과 나머지를 보는 거임!
=> 어차피 3으로 한 번 가나, 1로 세 번을 가나 이기는 자는 똑같음. 
ex) 1 1 3 / 1 1 1 1 1 
*/
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int x = N / 3; // 몫
    int y = N % 3; // 나머지
    if((x + y) % 2 == 0){
        cout << "CY" << '\n';
        return 0;
    }
    
    cout << "SK" << '\n';

    return 0;
}

#if 0
#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    if(N%2==0){
        cout << "CY" << '\n';
        return 0;
    }
    
    cout << "SK" << '\n';
    
    return 0;
}
#endif

/*
5
3 1 1

5 - 3 - 1 - 1
5 - 1 - 1 - 3 

7 (S)
3 3 1
1 1 1 1 1 1 1
3 1 1 1 1

4 (C)
3 1

6
3 3
1 1 1 1 1 1
3 1 1 1

10
3 3 3 1
3 3 1 1 1 1

8
3 3 1 1
3 1 1 1 1 1
==> 3*2 + 2

12
3 3 3 3
3*4

=> 3으로 나눴을 때의 몫과 나머지를 보는 거임!
=> 어차피 3으로 한 번 가나, 1로 세 번을 가나 이기는 자는 똑같음. 
ex) 1 1 3 / 1 1 1 1 1 
*/