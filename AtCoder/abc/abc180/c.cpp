#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    set<ll> st;
    for(ll i = 1; i*i <= n; ++i){
        if(n%i == 0){
            st.insert(i);
            st.insert(n/i);
        }
    }

    for(auto elem: st){
        cout << elem << "\n";
    }

    return 0;
}