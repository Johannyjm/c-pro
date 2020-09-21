#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    map<string, int> cntb, cntr;
    int n;
    cin >> n;
    string s;
    rep(i, n){
        cin >> s;
        ++cntb[s];
    }
    int m;
    cin >> m;
    rep(i, m){
        cin >> s;
        ++cntr[s];
    }

    int res = 0;
    for(auto e: cntb){
        res = max(res, e.second-cntr[e.first]);
    }

    cout << res << endl;


    return 0;
}