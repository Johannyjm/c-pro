#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
typedef long long ll;
using mint = modint1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<mint> cnt(26, 0);
    rep(i, n) ++cnt[s[i] - 'a'];

    mint res = 1;
    rep(i, 26) res *= cnt[i]+1;

    cout << res.val()-1 << endl;

    return 0;
}