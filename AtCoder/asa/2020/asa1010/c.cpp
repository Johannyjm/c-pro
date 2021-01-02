#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    ll xo;
    cin >> xo;
    bool flg = false;
    set<ll> st;
    rep1(i, n){
        ll a;
        cin >> a;
        st.insert(a);

        xo ^= a;
        if(i < n-1 && xo == 0){
            flg = true;
        }
    }

    if(st.size() > 3 && flg)puts("No");
    else if(xo == 0) puts("Yes");
    else puts("No");

    return 0;
}