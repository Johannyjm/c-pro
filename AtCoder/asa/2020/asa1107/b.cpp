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
    cin >> n;
    map<string, int> cntp, cntn;
    rep(i, n){
        string s;
        cin >> s;
        ++cntp[s];
    }
    cin >> m;
    rep(i, m){
        string s;
        cin >> s;
        ++cntn[s];
    }

    int res = 0;
    for(auto k: cntp){
        int sm = k.second - cntn[k.first];

        res = max(res, sm);
    }

    cout << res << endl;



    return 0;
}