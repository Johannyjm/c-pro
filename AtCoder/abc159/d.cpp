#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> bucket(n+1, 0);
    rep(i, n+1) {
        ll num;
        cin >> num;
        a[i] = num;
        ++bucket[num];
    }
 
    ll sum = 0;
    rep(i, n) sum += bucket[i] * (bucket[i] - 1) / 2;


    rep(i, n){
        if(bucket[a[i]] < 2) cout << sum << endl;
        else cout << sum - bucket[a[i]] + 1 << endl;
    }

    return 0;
}