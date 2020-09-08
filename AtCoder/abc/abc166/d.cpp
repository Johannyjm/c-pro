#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<ll> divisor(ll n) {
  vector<ll> ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll x;
    cin >> x;

    vector<ll> d = divisor(x);

    rep(i, d.size()){
        ll cand = d[i];
        for(ll b = -cand; b <= cand; ++b){
            ll a = cand + b;

            if(pow(a, 5) - pow(b, 5) == x){
                cout << a << " " << b << endl;
                return 0;
            }
        }

    }

    return 0;
}