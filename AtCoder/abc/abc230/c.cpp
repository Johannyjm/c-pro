#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, a, b, p, q, r, s;
    cin >> n >> a >> b >> p >> q >> r >> s;

    for(ll i = p; i <= q; ++i){
        for(ll j = r; j <= s; ++j){
            if(i+j == a+b || i-j == a-b) cout << "#";
            else cout << ".";
        }
        cout << endl;
    }
    

    return 0;
}