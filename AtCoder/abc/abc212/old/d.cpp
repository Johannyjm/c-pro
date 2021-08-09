#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    vector<pair<int, ll>> queries(q);
    rep(i, q){
        int p;
        cin >> p;
        if(p == 3) queries[i] = {p, -1};
        else{
            ll x;
            cin >> x;
            queries[i] = {p, x};
        }
    }

    vector<ll> add(q, 0);
    rep(i, q){
        if(i == 0){
            if(queries[i].first == 2){
                add[i] = queries[i].second;
            }
            continue;
        }

        add[i] += add[i-1];
        if(queries[i].first == 2) add[i] += queries[i].second;
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    rep(i, q){
        if(queries[i].first == 1){
            pq.push({queries[i].second, i});
        }
        if(queries[i].first == 3){
            auto [val, idx] = pq.top();
            pq.pop();

            ll bias;
            if(idx == 0) bias = add[i];
            else bias = add[i] - add[idx-1];

            cout << val + bias << "\n";
        }
    }

    return 0;
}