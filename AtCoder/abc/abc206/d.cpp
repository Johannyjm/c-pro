#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    
    dsu uf(220000);
    rep(i, n){
        if(i >= n-i-1) break;
        if(a[i] != a[n-i-1]) uf.merge(a[i], a[n-i-1]);
    }

    int res = 0;
    for(auto group: uf.groups()){
        res += group.size() - 1;
    }

    cout << res << endl;



    return 0;
}