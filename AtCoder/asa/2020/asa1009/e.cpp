#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll n, m, v, p;
vector<ll> a;
bool check(ll idx){
    ll border = a[idx] + m;
    ll voted = idx + p;

    ll vote = 0;
    for(int i = idx+1; i < n-(p-1); ++i){
        if(a[i] > border) return false;
        vote += min(m, border-a[i]);
    }

    voted += vote/m;

    // cout << border << " " << vote << " " << voted << endl;

    return voted >= v;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> v >> p;
    a.resize(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    // rep(i, n) cout << a[i] << " ";
    // cout << endl;

    // if(check(0)){
    //     cout << n << endl;
    //     return 0;
    // }

    ll ok = n-1;
    ll ng = -1;

    while(abs(ok-ng) > 1){
        ll mid = (ok+ng) / 2;

        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << n-ok << endl;

    return 0;
}