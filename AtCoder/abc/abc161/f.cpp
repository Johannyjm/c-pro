#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll n, res;

void dfs(ll k){
    if(k == n) {
        ++res;
        return;
    }
    if(k > n) return;

    if(k != 1)dfs(k*k);
    dfs(2*k);
    dfs(k*(k+1));
    dfs(2*k+1);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;

    res = 0;

    dfs(1);

    cout << res << endl;

    return 0;
}