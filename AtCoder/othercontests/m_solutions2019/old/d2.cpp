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
    vector<vector<int>> g(n);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> c(n);
    int res = 0;
    rep(i, n){
        cin >> c[i];
        res += c[i];
    }

    vector<pair<int, int>> di(n);
    rep(v, n){
        di[v] = {g[v].size(), v};
    }

    sort(di.begin(), di.end(), greater<pair<int, int>>());
    sort(c.begin(), c.end(), greater<int>());

    res -= c.front();
    vector<int> d(n);
    rep(i, n){
        d[di[i].second] = c[di[i].second];
    }

    cout << res << endl;
    rep(i, n-1) cout << d[i] << " ";
    cout << d.back() << endl;



    return 0;
}