#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;
template<typename T>
vector<T> compress(vector<T> &a){
    vector<T> ret = a;
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    for(int i = 0; i < (int)a.size(); ++i){
        a[i] = lower_bound(ret.begin(), ret.end(), a[i]) - ret.begin();
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll h, w, n;
    cin >> h >> w >> n;

    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    compress(a);
    compress(b);


    rep(i, n){
        cout << a[i]+1 << " " << b[i]+1 << "\n";
    }



    return 0;
}