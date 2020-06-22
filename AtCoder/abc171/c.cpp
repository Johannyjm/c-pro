#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

class Radix {
private:
  const char* s;
  ll a[128];
public:
  Radix(const char* s = "abcdefghijklmnopqrstuvwxyz") : s(s) {
    ll i;
    for(i = 0; s[i]; ++i)
      a[(ll)s[i]] = i;
  }
  string to(long long p, ll q) {
    ll i;
    if(!p)
      return "0";
    char t[64] = { };
    for(i = 62; p; --i) {
      t[i] = s[p % q];
      p /= q;
    }
    return string(t + i + 1);
  }
  string to(const string& t, int p, int q) {
    return to(to(t, p), q);
  }
  long long to(const string& t, int p) {
    ll i;
    long long sm = a[(int)t[0]];
    for(i = 1; i < (ll)t.length(); ++i)
      sm = sm * p + a[(ll)t[i]];
    return sm;
  }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    --n;

    Radix r;

    string res = r.to(n, 26);
    rep(i, res.size()-1){
        
        cout << char(res[i]-1);
    }
    cout << res.back() << endl;

    return 0;
}