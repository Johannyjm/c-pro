#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

template<typename T>
vector<T> compress(vector<T> &a){
    vector<T> ret = a;
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    for(int i = 0; i < (int)a.size(); ++i){
        a[i] = lower_bound(ret.begin(), ret.end(), a[i]) - ret.begin();
    }
    return ret;
}

int points[4400][4400];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> xy;
    rep(i, n){
        int x, y;
        cin >> x >> y;
        xy.push_back(x);
        xy.push_back(y);
    }

    compress(xy);
    vector<int> x, y;
    rep(i, 2*n){
        if(i%2 == 0) x.push_back(xy[i]);
        else y.push_back(xy[i]);
    }

    // rep(i, n) cout << x[i] << " " << y[i] << endl;

    vector<ll> xcnt(4400, 0), ycnt(4400, 0);
    rep(i, n){
        ++xcnt[x[i]];
        ++ycnt[y[i]];
    }

    vector<vector<int>> gx(4400);
    rep(i, n){
        gx[x[i]].push_back(y[i]);
    }


    rep(i, n){
        points[x[i]][y[i]] = 1;
    }

    ll res = 0;
    rep(i, 4400){
        if(xcnt[i] < 2) continue;
        rep(j, 4400){
            if(i == j) continue;
            int count = 0;
            for(auto yv: gx[i]){
                count += points[j][yv];
            }
            res += count * (count-1) / 2;
        }
    }

    cout << res/2 << endl;




    return 0;
}