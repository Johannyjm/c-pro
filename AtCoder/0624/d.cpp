#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    priority_queue<ll> pq;
    rep(i, n){
        cin >> a[i];
        pq.push(a[i]);
    }


    rep(_, m){
        ll t = pq.top();
        pq.pop();
        t /= 2;
        pq.push(t);
    }

    ll res = 0;
    rep(i, n){
        res += pq.top();
        pq.pop();
    }

    cout << res << endl;

    return 0;
}