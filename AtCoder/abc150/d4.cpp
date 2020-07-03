#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    set<ll> st;
    rep(i, n){
        cin >> a[i];
        if(i!=0){
            if(a[i] / 2 % 2 != a[i-1] / 2 % 2){
                cout << 0 << endl;
                return 0;
            }
        }
        st.insert(a[i]);
    }
    sort(a.begin(), a.end(), greater<ll>());

    if(a[0] == 2){
        cout << (n+1)/2 << endl;
    }

    map<ll, ll> cand;
    ll base = a[0];
    ll now = a[0] / 2;
    while(now <= m){
        ++cand[now];
        now += base;
    }

    rep1(i, n){
        ll base = a[i];
        ll now = a[i] / 2;
        while(now <= m){
            if(cand[now] > 0) ++cand[now];
            now += base;
        }
    }

    ll res = 0;
    for(auto itr = cand.begin(); itr != cand.end(); ++itr){
        if(itr->second == n) ++res;
    }

    cout << res << endl;




    return 0;
}