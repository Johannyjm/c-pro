#include <bits/stdc++.h>
using namespace std;


int digits_sum(int num){
    int ret = 0;

    while(num > 0){
        ret += num % 10;
        num /= 10;
    }
    return ret;
}

int main(){
    int N;
    cin >> N;
    int res = 1e9;

    for(int a = 1; a < N; ++a){
        int b = N - a;
        int tmp = digits_sum(a) + digits_sum(b);
        if(tmp < res) res = tmp;
    }

    cout << res << endl;
}