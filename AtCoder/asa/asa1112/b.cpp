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
    map<string, int> cnt1, cnt2;
    rep(i, n){
        string s;
        cin >> s;
        ++cnt1[s];
    }
    int m;
    cin >> m;
    rep(i, m){
        string s;
        cin >> s;
        ++cnt2[s];
    }

    int res = 0;
    for(auto k: cnt1){
        int sm = k.second - cnt2[k.first];
        res = max(res, sm);
    }

    cout << res << endl;

    return 0;
}