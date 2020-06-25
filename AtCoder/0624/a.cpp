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

    vector<int> k(n-1);
    rep(i, n-1) cin >> k[i];

    vector<int> res(n);
    res[0] = k[0];
    rep1(i, n){
        res[i] = min(k[i], k[i-1]);
    }
    res[n-1] = k[n-2];

    rep(i, n) cout << res[i] << " ";
    cout << endl;

    return 0;
}