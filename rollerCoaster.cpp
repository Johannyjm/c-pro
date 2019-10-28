#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, K, h;
    cin >> N >> K;
    int res = 0;
    for(int i = 0; i < N; ++i){
        cin >> h;

        if(h >= K) res++;
    }
    cout << res << endl;
}