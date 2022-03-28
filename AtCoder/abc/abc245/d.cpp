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
    vector<int> a(n+1), c(n+m+1);
    rep(i, n+1) cin >> a[i];
    rep(i, n+m+1) cin >> c[i];

    vector<int> res(m+1);
    rep(i, m+1){
        int d = c.back() / a.back();
        res[m-i] = d;
        rep(j, n+1){
            c[n+m-j-i] -= d * a[n-j];
        }
        c.pop_back();

    }

    for(auto e: res) cout << e << " ";
    cout << endl;

    return 0;
}