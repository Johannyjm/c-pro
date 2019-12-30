#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;
    ll A[N];
    ll res = 1e18;

    for (ll i = 0; i < N; ++i) cin >> A[i];

    for (ll bit = 0; bit < (1<<N); ++bit) {
        ll mul = 1;

        for (ll i = 0; i < N; i++) {
            if (bit & (1<<i)) {
                mul *= A[i];
            }
        }
        if(abs(M - mul) < abs(M - res)) res = mul;
    }
    cout << res << endl;

}