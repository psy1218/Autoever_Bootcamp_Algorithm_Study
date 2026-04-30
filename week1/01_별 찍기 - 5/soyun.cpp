#if 0
#include <iostream>
#include <vector>
using namespace std;

int main(){

    int N;
    cin >> N;

    vector<vector<string>>star(N, vector<string>(2*N-1));

    for(int i=1;i<=N;i++){
        int star_cnt = 2 * i - 1;
        int space = N - i;
        
        for(int j=0;j<star_cnt;j++){
            star[i-1][space + j] = '*';
        }
    }

    for(auto a:star){
        for(auto b:a){
            cout << b;
        }
        cout << '\n';
    }

    return 0;
}

/*
5
*
***
*****
*******
*********
*/
#endif

#include <iostream>
#include <vector>
using namespace std;

int main(){

    int N;
    cin >> N;

    for(int i=1;i<=N;i++){
        int star_cnt = 2 * i - 1; // 별 개수
        int space = N - i; // 공백 종료 시점
        
        for(int k=0;k<space;k++){
            cout << ' ' ;
        }
        
        for(int j=0;j<star_cnt;j++){
            cout << '*';
        }

        cout << '\n';
    }

    return 0;
}


/*
    *     4 + 1 -> 5(index 4)번째부터 1칸
   ***    3 + 3
  *****   2 + 5
 *******  1 + 7 
********* 0 + 9
         N  star_cnt
*/