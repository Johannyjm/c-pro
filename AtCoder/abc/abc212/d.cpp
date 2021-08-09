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
    
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll bias = 0;
    rep(i, q){
        int p;
        cin >> p;
        if(p == 1){
            ll x;
            cin >> x;
            pq.push(x - bias);
        }
        if(p == 2){
            ll x;
            cin >> x;
            bias += x;
        }
        if(p == 3){
            ll val = pq.top();
            pq.pop();

            cout << val + bias << "\n";
        }

    }

    return 0;
}