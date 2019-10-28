#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int T[N];
    for (int i = 0; i < N; ++i) cin >> T[i];

    int M;
    cin >> M;
    int tmp[N];
    int res[M] = {0};

    for (int m = 0; m < M; ++m){
        
        int P, X;
        cin >> P >> X;
        for(int i = 0; i < N; ++i) tmp[i] = T[i];

        tmp[P - 1] = X;

        for(int i = 0; i < N; ++i) res[m] += tmp[i];
    }

    for(int i = 0; i < M; ++i) cout << res[i] << endl;

}