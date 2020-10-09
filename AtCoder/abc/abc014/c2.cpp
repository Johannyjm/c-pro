#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> cnt(1000002, 0);
    rep(_, n){
        int a, b;
        cin >> a >> b;
        ++cnt[a];
        --cnt[b+1];
    }

    rep(i, 1000001) cnt[i+1] += cnt[i];


    ll res = 0;
    rep(i, 1000002) res = max(res, cnt[i]);

    cout << res << endl;

    return 0;
}