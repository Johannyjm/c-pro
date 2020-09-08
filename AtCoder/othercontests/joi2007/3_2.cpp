#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
vector<int> x, y;

int calc_dist2(int i, int j){
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    x.assign(n, 0);
    y.assign(n, 0);
    map<pair<int, int>, int> mp;

    rep(i, n){
        cin >> x[i] >> y[i];
        ++mp[make_pair(x[i], y[i])];
    }

    int res = 0;
    for(int i = 0; i < n-2; ++i){
        for(int j = i+1; j < n-1; ++j){
            int edge2ed1 = calc_dist2(i, j);

            if(edge2ed1 > res){
                for(int k = j+1; k < n; ++k){
                    int edge2ed2 = calc_dist2(i, k);
                    if(edge2ed2 != edge2ed1) continue;
                    if((x[j]-x[i])*(y[j]-y[i]) + (x[k]-x[i])*(y[k]-y[i]) != 0) continue; // inner product

                    pair<int, int> vec = make_pair(x[j]+x[k]-x[i], y[j]+y[k]-y[i]); // target vector from origin
                    if(mp[vec]) res = max(res, edge2ed1);
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}