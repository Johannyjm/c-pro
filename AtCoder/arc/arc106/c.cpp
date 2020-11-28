#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

vector<ll> l, r;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    if(m < 0){
        cout << -1 << endl;
        return 0;
    }

    if(n <= 2){
        if(m == 0) cout << 1 << " " << 2 << endl;
        else cout << -1 << endl;
        return 0;
    }

    if(m > n-2){
        cout << -1 << endl;
        return 0;
    }

    l.push_back(1);
    r.push_back(100000000);

    ll bl = 2;
    ll br = 3;
    rep(i, m+1){
        l.push_back(bl);
        r.push_back(br);
        bl += 2;
        br += 2;
    }

    int rest = n-m-2;
    bl = 100000001;
    br = 100000002;
    rep(i, rest){
        l.push_back(bl);
        r.push_back(br);
        bl += 2;
        br += 2;
    }

    rep(i, n) cout << l[i] << " " << r[i] << endl;

    return 0;
}