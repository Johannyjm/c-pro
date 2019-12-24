#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll bucket[100001] = {0};
    ll res = 0;

    for (ll i = 0; i < n; ++i){
        ll a;
        cin >> a;
        if(a > 100000)res++;
        else bucket[a-1] += 1;
    }

    for(ll i = 0; i < 10; ++i) cout << bucket[i];
    cout << endl;

    for (ll i = 0; i < 100001; ++i){
        if(bucket[i] != 0 && bucket[i] != i+1) {
            if(bucket[i] < i+1) res += bucket[i];
            else res += bucket[i] - i - 1;
        }
    }
    cout << res << endl;


}