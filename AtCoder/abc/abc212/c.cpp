#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(j, m) cin >> b[j];

    sort(b.begin(), b.end());

    int res = 1001001001;
    rep(i, n){
        int key = a[i];
        int idx = lower_bound(b.begin(), b.end(), key) - b.begin();
        
        res = min({res, abs(key - b[min(m-1, idx)]), abs(key - b[max(0, idx-1)])});
    }

    cout << res << endl;

    return 0;
}