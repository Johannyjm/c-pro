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

    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vector<int> imos(1000002);
    rep(i, n){
        ++imos[a[i]];
        --imos[b[i]+1];
    }

    int res = 0;
    rep(i, 1000002){
        imos[i] += imos[i-1];
        res = max(res, imos[i]);
    }

    cout << res << endl;

    return 0;
}