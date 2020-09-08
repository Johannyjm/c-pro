#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    set<ll> divisors = divisor(n);

    ll sm = 0;
    for(auto ele: divisors){
        if(ele == n) continue;

        sm += ele;
    }

    if(sm < n) puts("Deficient");
    else if(sm == n) puts("Perfect");
    else puts("Abundant");

    return 0;
}