#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    ll cnt_neg = 0;
    ll sm = 0;
    ll mn = 1001001001;
    rep(i, n){
        cin >> a[i];
        if(a[i] < 0) ++cnt_neg;

        sm += abs(a[i]);
        mn = min(mn, abs(a[i]));
    }

    if(cnt_neg % 2 == 0) cout << sm << endl;
    else cout << sm - mn*2 << endl;
    
    return 0;
}