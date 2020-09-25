#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, m) cin >> c[i] >> d[i];

    rep(i, n){
        int res = -1;
        int mn = 1001001001;
        rep(j, m){
            int di = abs(a[i]-c[j]) + abs(b[i]-d[j]);
            if(di < mn){
                mn = di;
                res = j+1;
            }
        }
        cout << res << endl;
    }   

    return 0;
}