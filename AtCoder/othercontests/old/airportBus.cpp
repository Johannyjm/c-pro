#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll N, C, K;
    cin >> N >> C >> K;
    ll T[N];
    for(int i = 0; i < N; ++i) cin >> T[i];
    sort(T, T + N);
    int step = 1;
    ll res = 0;
    ll gain;

    for(int i = 1; i < N; ++i){

        if(step == 1 and T[i] - T[i - 1])
    }

    // while(N - ptr > 1){

    //     for(int i = 0; i < min(C - 1, N - ptr); ++i){
    //         gain = 1;

    //         if(T[ptr + i + 1] - T[ptr] < K){
    //             gain = i + 2;
    //         }
    //     }
    //     cout << gain << endl;
    //     ptr += gain;
    //     res++;
    // }

    cout << res + (ptr < N) << endl;

}