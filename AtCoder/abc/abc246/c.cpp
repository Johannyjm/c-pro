#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k, x;
    cin >> n >> k >> x;

    priority_queue<ll> pq;
    for(int i = 0; i < n; ++i){
        ll a;
        cin >> a;
        pq.push(a);
    }

    for(int i = 0; i < k; ++i){
        ll val = pq.top();
        pq.pop();

        val = max(0ll, val - x);

        pq.push(val);
    }

    ll res = 0;
    while(!pq.empty()){
        ll val = pq.top();
        pq.pop();

        res += val;
    }

    cout << res << endl;

    return 0;
}
