#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    s[0][0] = s[0][w-1] = s[h-1][0] = s[h-1][w-1] = '#';

    dsu uf(h+w);
    rep(i, h) rep(j, w){
        if(s[i][j] == '#') uf.merge(i, h+j);
    }

    int res1 = 0;
    int res2 = 0;
    for(auto group: uf.groups()){
        bool x = false;
        bool y = false;
        for(auto member: group){
            if(member < h) x = true;
            else y = true;
        }
        if(x) ++res1;
        if(y) ++res2;
    }

    cout << min(res1-1, res2-1) << endl;

    return 0;
}