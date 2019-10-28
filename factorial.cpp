#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    ll res = 1;
    ll MOD = 1e9 + 7;

    for (ll i = 1; i <= N; ++i){
        res = res * i % MOD;
    }
    cout << res << endl;
    
    
}