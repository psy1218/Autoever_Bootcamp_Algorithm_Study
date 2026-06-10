#include <vector>
using namespace std;
// 곱이 높으려면 수의 간격이 작아야함. 

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if (s < n) return {-1};
    
    int q = s / n; // 가운데의 기본으로 깔리는 거
    int r = s % n; // 가운데의 기본 외에 필요한 거 - 나머지 추가
    
    // 앞에는 q를 넣고
    for (int i = 0; i < n - r; i++) {
        answer.push_back(q);
    }
    
    // 뒤에는 q+1을 r개 넣기 - 딱 맞았으면 여기 오지도 않음. 
    for (int i = 0; i < r; i++) {
        answer.push_back(q + 1);
    }
    
    return answer;
}

// 브루트방식.. ..  시간 초과 
// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include <numeric>

// using namespace std;

// int cnt = 0;
// vector<vector<int>>Info;
// vector<int>Data;
// vector<vector<int>>res;

// int num = 0;

// void check(vector<int>& Data, int s){
//     int sum = accumulate(Data.begin(), Data.end(),0);
//     int mul = accumulate(Data.begin(), Data.end(),1,multiplies<int>());
//     vector<int>temp;
//     temp = Data;
//     temp.push_back(mul);
//     if(sum != s) return;
    
//     // num +=1;
//     // for(int k=0;k<temp.size();k++){
//     //     cout << temp[k] << ' ';
//     // }
//     // cout << '\n';
//     // cout << "sum: " << sum << "mul: " << mul<<'\n';
    
//     if(!Info.empty()) {
//         if(Info[0][temp.size()-1] < mul ){
//             Info.clear();
//             Info.push_back(temp);
//         }
//         if(Info[0][temp.size()-1] == mul ){
//             Info.push_back(temp);
//         }
//     } 
//     else{
//          Info.push_back(temp);
//     }
// }


// void dfs(int start, int cnt, int n, int s){
//     if(cnt >= n){
//         // for(int i=0;i<n;i++){
//         //     cout << Data[i] << " ";
//         // }
//         // cout << '\n';
//         check(Data, s);
//         // for(int i=0;i<n;i++){
//         //     cout << Data[i] << " ";
//         // }
//         // cout << '\n';
//         return;
//     }
    
//     for(int i = start;i<=s;i++){
//         Data.push_back(i);
//         dfs(i, cnt+1,n,s);
//         Data.erase(Data.end()-1);
//     }
// }

// vector<int> solution(int n, int s) {
//     vector<int> answer;
    
//     dfs(1,0, n ,s);
    
//     sort(Info.begin(),Info.end());
  
    
    
//     if(Info.empty()){
//         answer.push_back(-1);
//     }
//     else{
//         // cout << '[';
//         // for(int i=0;i<Info[0].size()-1;i++){
//         //     if(i==Info[0].size()-2){
//         //         cout <<Info[0][i] << ']';
//         //     }
//         //     else cout << Info[0][i] << ", ";
//         // }
        
//         Info[0].erase(Info[0].end()-1);
//         answer = Info[0];
//     }
    
//     return answer;
// }

// /*

// 3 9
// 1 1 7 = 7
// 1 2 6 = 12
// 1 3 5 = 15
// 1 4 5 = 20
// 2 2 5 = 20
// 2 3 4 = 24
// 3 3 3 = 27


// 3 8
// 1 1 6
// 1 2 5
// 1 3 4
// 2 2 4
// 2 3 3
// 3 4 1


// */