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
    vector<ll> l(n);
    rep(i, n) cin >> l[i];

    int res = 0;
    rep(a, n) rep(b, n) rep(c, n){
        if(!(a < b && b < c)) continue;

        if(l[a] != l[b] && l[b] != l[c] && l[c] != l[a]){
            if(l[a]+l[b] > l[c] && l[b]+l[c] > l[a] && l[c]+l[a] > l[b]) ++res;
        }
    }

    cout << res << endl;

    return 0;
}