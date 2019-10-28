#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int bars[N];

    for(int i = 0; i < N; ++i) cin >> bars[i];

    sort(bars, bars + N, greater<int>());

    int res = 0;

    for(int i = 0; i < K; ++i){
        res += bars[i];
    }
    cout << res << endl;
}