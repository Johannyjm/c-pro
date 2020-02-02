#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, k;
    cin >> a >> k;
    ll current = a;
    int res = 0;

    if(!k){
        cout << 2000000000000 - a << endl;
        return 0;
    }

    while(current < 2000000000000){
        current += 1 + k*current;
        ++res;
    }

    cout << res << endl;

    return 0;
}