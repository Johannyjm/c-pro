#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    dsu d(n);
    rep(i, q){
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0){
            d.merge(u, v);
        }
        else{
            if(d.same(u, v)) puts("1");
            else puts("0");
        }
    }
    
    return 0;
}