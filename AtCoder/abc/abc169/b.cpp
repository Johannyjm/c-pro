#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> A(n);
    rep(i, n){
        cin >> A[i];
        if(A[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    }

    ll res = 1;
    rep(i, n){
        res *= A[i];

        if(res > 1000000000000000000){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << res << endl;

    return 0;
}