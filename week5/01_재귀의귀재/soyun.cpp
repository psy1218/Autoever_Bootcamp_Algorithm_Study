#include <iostream>
using namespace std;

int cnt = 0;

int recursion(string& word, int l, int r){ // string 배열을 & 안 해서, 참조가 아닌 문자열 복사함. 그래서 시간 초과  
    cnt ++;
    if(l >= r) return 1;
    else if(word[l] != word[r]) return 0;
    else return recursion(word, l+1, r-1);
}

void isPalindrome(string& word){
    cnt = 0;
    cout << recursion(word, 0, word.size()-1) << ' ' << cnt << '\n';
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    string word;

    cin >> T;

    for(int i=0;i<T;i++){
        cin >> word;
        isPalindrome(word);
    }

    return 0;
}