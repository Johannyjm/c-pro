#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int cnt = 0;
    int num = N - 1;

    while(num > 0){
        num /= 2;
        cnt++;
    }
    cout << floor(pow(2, cnt - 1)) << endl;
}