#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    rep(i, n) cin >> p[i];
    sort(p.begin(), p.end());

    int res = 0;
    rep(i, k){
        res += p[i];
    }

    cout << res << endl;

    return 0;
}