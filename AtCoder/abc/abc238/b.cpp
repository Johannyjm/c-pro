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
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> digs = {0};
    for(auto e: a){
        rep(i, (int)digs.size()){
            digs[i] += e;
            digs[i] %= 360;
        }

        digs.push_back(0);
    }

    sort(digs.begin(), digs.end());

    int res = 0;
    rep(i, (int)digs.size()-1){
        res = max(res, digs[i+1] - digs[i]);
    }

    res = max(res, 360 - digs.back());

    cout << res << endl;

    return 0;
}