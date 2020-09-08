#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

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

ll two_d(ll n){
    ll ret = 0;
    while(n){
        if(n%2 == 0){
            ++ret;
            n /= 2;
        }
        else break;
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    set<ll> st;
    rep(i, n){
        cin >> a[i];
        st.insert(a[i]);
        if(i!=0){
            if(a[i] / 2 % 2 != a[i-1] / 2 % 2 || two_d(a[i]) != two_d(a[i-1])){
                cout << 0 << endl;
                return 0;
            }
        }
    }

    ll lscm = 1;
    for(auto elem: st){

        lscm = lcm(lscm, elem/2);
        if(lscm > m){
            cout << 0 << endl;
            return 0;
        }
    }

    ll res = (lscm <= m);
    res += (m-lscm) / (lscm*2);

    cout << res << endl;


    return 0;
}