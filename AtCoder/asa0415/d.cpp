#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

bool is_prime(int n){
    if(n == 1) return false;
    
    for(int i = 2; i*i <= n; ++i){
        if(n%i == 0) return false;
    }

    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll q;
    cin >> q;

    vector<ll> numlikeprime(100001, 0);
    rep(i, 100002){
        if(i<2) continue;
        numlikeprime[i] = numlikeprime[i-1];
        if(is_prime(i) && is_prime((i+1)/2)) ++numlikeprime[i];
    }

    rep(i, q){
        int l, r;
        cin >> l >> r;

        cout << numlikeprime[r] - numlikeprime[l-1] << "\n";
    }

    return 0;
}