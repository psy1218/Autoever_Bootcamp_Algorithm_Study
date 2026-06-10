#include <iostream>
#include <vector>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;

    vector<string>day(7);
    day = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};


    int d_cnt=0, res=0;
    for(int i=1;i<x;i++){ //조건 잘 보기!!
        if(i==2) d_cnt += 28;
        if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12){
            d_cnt += 31;
        }
        if(i==4 || i==6 || i==9 || i==11){
            d_cnt += 30;
        }
    }


    d_cnt += y;

    res = d_cnt % 7;
    cout << day[res] << '\n';
    return 0;
}

/*
1  1  - MON
2  28 - WED
3  14 - WED
9  2  - SUN
12 25 - TUE 

2 28 -> 31+28 = 59-56 = 3
28+31+14 = 28 + 45 = 73 /7 =3 

1 3 5 7 = 31* 4 = 124
2 4 6 8 = 30*3 + 28 = 118
244 / 7 = 34 - 28 = 6

1 3 5 7 9 11 31*6 = 186
2 4 6 8 10 90 + 31 + 28 = 149
335 = 25 = 360/7 10-7 = 3
*/

#if 0 
#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<string>day(7);
    day = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    vector<vector<string>>M1(5, vector<string>(7));
    vector<vector<string>>M2(5, vector<string>(7));
    vector<vector<string>>M3(5, vector<string>(7));
    vector<vector<string>>M4(5, vector<string>(7));
    vector<vector<string>>M5(5, vector<string>(7));
    vector<vector<string>>M6(5, vector<string>(7));
    vector<vector<string>>M7(5, vector<string>(7));
    vector<vector<string>>M8(5, vector<string>(7));
    vector<vector<string>>M9(6, vector<string>(7));
    vector<vector<string>>M10(5, vector<string>(7));
    vector<vector<string>>M11(5, vector<string>(7));
    vector<vector<string>>M12(6, vector<string>(7));

    // 1M
    for(int i=0;i<5;i++){
        for(int j=0;j<)
    }
    // 2M
    // 3M
    // 4M
    // 5M
    // 6M
    // 7M
    // 8M
    // 9M
    // 10M
    // 11M
    // 12M

    return 0;
}

/*
1  1  - MON
2  28 - WED
3  14 - WED
9  2  - SUN
12 25 - TUE 
*/
#endif