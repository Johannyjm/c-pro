#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    if(n < 3){
        cout << 1 << endl;
        return 0;
    }

    vector<int> x(n), y(n);
    map<pair<int, int>, int> mp;
    rep(i, n){
        cin >> x[i] >> y[i];
        ++mp[make_pair(x[i], y[i])];
    }

    int res = 51;
    rep(fir, n){
        rep(sec, n){
            if(fir == sec) continue;

            int cost = 1;
            int p = x[sec] - x[fir];
            int q = y[sec] - y[fir];


            int cx = x[sec];
            int cy = y[sec];
            rep(i, n-2){
                int nx = cx + p;
                int ny = cy + q;

                if(mp[make_pair(nx, ny)] > 0){
                    --mp[make_pair(nx, ny)];
                }
                else{
                    ++cost;
                }

                cx = nx;
                cy = ny;
            }

            res = min(res, cost);

        }
    }

    cout << res << endl;

    return 0;
}