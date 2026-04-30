// 최소 비용 = 비싼 것을 무료로 받는 것이 좋다. 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b){
    return a > b ;
}

int main(){
    int N, product;
    cin >> N;

    vector<int>products;
    for(int i=0;i<N;i++){
        cin >> product;
        products.push_back(product);
    }

    sort(products.begin(), products.end(), compare);

    int Sum = 0;
    for(int i=0;i<N;i++){
        if(i % 3 == 2) continue;
        Sum += products[i];
    }

    cout << Sum << '\n';
    return 0;
}