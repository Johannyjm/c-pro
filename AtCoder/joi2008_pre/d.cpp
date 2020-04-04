#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int m;
    cin >> m;
    
    vector<int> xm(m), ym(m);
    vector<pair<int, int>> vec(m);
    rep(i, m) {
        cin >> xm[i] >> ym[i];
        vec[i] = make_pair(xm[i] - xm[0], ym[i] - ym[0]);
    }

    int n;
    cin >> n;
    vector<int> xn(n), yn(n);
    set<pair<int, int>> xyn;
    rep(i, n) {
        cin >> xn[i] >> yn[i];
        xyn.insert(make_pair(xn[i], yn[i]));
    }

    rep(i, n){
        int x = xn[i];
        int y = yn[i];

        bool flg = true;
        rep(j, m){
            pair<int, int> nxt = make_pair(x+vec[j].first, y+vec[j].second);
            if(xyn.find(nxt) != end(xyn)) flg = flg && true;
            else flg = false;
        }

        if(flg){
            cout << xn[i] - xm[0] << " " << yn[i] - ym[0] << endl;
            return 0;
        }
    }


    return 0;
}