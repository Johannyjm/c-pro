#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> plus, minus;
    rep(i, n){
        int x;
        cin >> x;
        if(x < 0) minus.push_back(-x);
        else plus.push_back(x);
    }
    reverse(minus.begin(), minus.end());

    ll res = 1LL << 60;
    rep(i, minus.size()){
        ll cost = minus[i];
        int cnt = i+1;
        if(cnt >= k){
            res = min(res, cost);
            break;
        }

        cost += minus[i];

        if((int)plus.size() + cnt < k) continue;
        cost += plus[k - cnt - 1];

        res = min(res, cost);
    }

    rep(i, plus.size()){
        ll cost = plus[i];
        int cnt = i+1;
        if(cnt >= k){
            res = min(res, cost);
            break;
        }

        cost += plus[i];

        if((int)minus.size() + cnt < k) continue;
        cost += minus[k - cnt - 1];

        res = min(res, cost);
    }

    cout << res << endl;

    return 0;
}