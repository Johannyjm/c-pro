#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll tmp = n;
    ll res = 1;
    ll base = 2;
    while(tmp>1){
        res += base;
        base *= 2;
        tmp /= 2;
    }

    cout << res << endl;

    return 0;
}