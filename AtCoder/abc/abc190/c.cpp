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
    vector<int> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];
    int k;
    cin >> k;
    vector<int> c(k), d(k);
    rep(i, k) cin >> c[i] >> d[i];
    
    int res = 0;
    rep(i, 1<<k){
        vector<int> isd(k, 0);
        rep(j, k){
            if(i & (1<<j)){
                isd[j] = 1;
            }
        }

        vector<int> dish(n, 0);
        rep(j, k){
            if(isd[j]) dish[d[j]-1] = 1;
            else dish[c[j]-1] = 1;
        }

        int cnt = 0;
        rep(j, m){
            if(dish[a[j]-1] == 1 && dish[b[j]-1] == 1) ++cnt;
        }

        res = max(res, cnt);
    }

    cout << res << endl;

    return 0;
}