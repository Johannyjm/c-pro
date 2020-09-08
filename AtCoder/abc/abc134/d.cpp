#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

set<ll> divisor(ll n) {
    set<ll> ret;
    for(ll i = 1; i*i <= n; ++i) {
        if (n%i == 0) {
            ret.insert(i);
            if(i*i != n) ret.insert(n/i);
        }
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> res(n, 0);
    rep(i, n){
        if(a[i] == 1){
            res[i] = 1;
            set<ll> st = divisor(i+1);
            for(auto elem: st){
                if(i+1 == elem) continue;
                res[elem-1] += 1;
            }
        }

    }

    int end = -1;
    for(int i = n-1; i >= 0; --i){
        if(res[i] != 0){
            end = i;
            break;
        }
    }

    cout << end+1 << endl;
    rep(i, end+1) cout << res[i] << " ";
    cout << endl;



    return 0;
}