#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    priority_queue<ll> pq;
    rep(i, n){
        cin >> a[i];
        pq.push(a[i]);
    }


    rep(i, k){
        ll longest = pq.top();
        pq.pop();
        longest /= 2;
        pq.push(longest);
        pq.push(longest);

        cout << longest << endl;

        if(longest < 1.0) break;
    }

    // double res = pq.top();
    // if(res - int(res) == 0) cout << int(res) << endl;
    // else cout << int(res) + 1 << endl;
    cout << pq.top() << endl;

    return 0;
}