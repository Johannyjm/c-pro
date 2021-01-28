#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<pair<int, int>> cdy(n);
    rep(i, n){
        cin >> c[i] >> d[i];
        cdy[i] = {d[i], i};
    }
    sort(cdy.begin(), cdy.end());

    vector<bool> paired(n, false);
    int res = 0;
    rep(i, n){
        int idx = cdy[i].second;
        vector<int> cand;
        int mx_x = 0;
        rep(j, n){
            if(paired[j]) continue;
            if(a[j] < c[idx] && b[j] < d[idx]){
                cand.push_back(j);
                mx_x = max(mx_x, a[j]);
            }
        }
        for(auto j: cand){
            if(a[j] == mx_x){
                ++res;
                paired[j] = true;
                break;
            }
        }

    }

    cout << res << endl;    

    return 0;
}