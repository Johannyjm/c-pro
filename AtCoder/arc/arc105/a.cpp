#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n = 4;
    vector<ll> a(n);
    ll whole = 0;
    rep(i, n){
        cin >> a[i];
        whole += a[i];
    }
    rep1(i, (1<<4)){
        vector<int> use(4, 0);
        ll sm = 0;
        rep(j, n){
            if(i & (1<<j)) sm += a[j];
        }

        if(sm == whole - sm) {
            puts("Yes");
            return 0;
        }        
    }


    puts("No");

    return 0;
}