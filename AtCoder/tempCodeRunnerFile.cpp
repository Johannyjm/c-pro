#include <bits/stdc++.h>
using namespace std;

int d(int n){
    int res = 1;
    while(n > 0){
        n/10;
        res++;
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; ++i){
        if(n % 2 == 1)res++;
    }
    cout << d(32654) << endl;
}