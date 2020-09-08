#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

ll gcd(ll m, ll n){
    ll tmp;
    while(m%n){
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return n;
}

ll lcm(ll m, ll n){
    return m / gcd(m, n) * n;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    
    string s, t;
    cin >> s >> t;

    ll l = lcm(n, m);

    ll ss = l/n;
    ll st = l/m;
    ll ptr_s = 0;
    ll ptr_t = 0;
    while(ptr_s<l && ptr_t<l){
        if(ptr_s == ptr_t){
            if(s[ptr_s] != t[ptr_t]){
                cout << -1 << endl;
                return 0;
            }
            ptr_s += ss;
            ptr_t += st;
        }
        
        else if(ptr_s < ptr_t) ptr_s += ss;
        else ptr_t += st;
    }

    cout << l << endl;

    return 0;
}