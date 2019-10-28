#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int T[N];
    int sum = 0;
    for(int i = 0; i < N; ++i){
        cin >> T[i];
        sum += T[i];
    }
    
    int M;
    cin >> M;
    int res[M];

    for (int i = 0; i < M; ++i){
        int X, P;
        cin >> X >> P;

        res[i] = sum - (T[X - 1] - P);
    }

    for (int i = 0; i < M; ++i) cout << res[i] << endl;

}