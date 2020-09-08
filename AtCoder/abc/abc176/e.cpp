#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll h, w, m;
    cin >> h >> w >> m;

    vector<ll> a(m), b(m);
    vector<ll> hcnt(h+10, 0), wcnt(w+10, 0);
    ll hmx = 0;
    ll wmx = 0;
    map<pair<int, int>, int> grid;
    rep(i, m){
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
        grid[{a[i], b[i]}] = 1;

        ++hcnt[a[i]];
        ++wcnt[b[i]];
        if(hcnt[a[i]] > hmx){
            hmx = hcnt[a[i]];
        }
        if(wcnt[b[i]] > wmx){
            wmx = wcnt[b[i]];
        }
    }

    vector<int> hmxs, wmxs;
    rep(i, h){
        if(hcnt[i] == hmx) hmxs.push_back(i);
    }
    rep(i, w){
        if(wcnt[i] == wmx) wmxs.push_back(i);
    }

    int hh = hmxs[0];
    int ww = wmxs[0];
    bool found = false;
    for(auto hi: hmxs) for(auto wj: wmxs){
        if(grid[{hi, wj}] == 0){
            hh = hi;
            ww = wj;
            found = true;
            break;
        }
    }

    if(found) cout << hcnt[hh] + wcnt[ww] << endl;
    else cout << hcnt[hh] + wcnt[ww] -1 << endl;
    
    return 0;
}