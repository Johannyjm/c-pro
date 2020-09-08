#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll k, a, b;
    cin >> k >> a >> b;

    if(b-a<=2) {
        cout << k+1 << endl;
        return 0;
    }

    ll remain = k - (a-1);
    ll res = a;

    if(remain%2) {
        --remain;
        ++res;
    }

    
    res += (b-a) * (remain/2);

    cout << res << endl;

    return 0;
}