#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, K, X, Y;
    cin >> N >> K >> X >> Y;

    int res = 0;
    
    if(N <= K) cout << N * X << endl;
    else cout << K * X + (N - K) * Y << endl;
    return 0;
}