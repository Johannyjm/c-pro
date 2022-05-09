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

    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector<ll> ab;
    rep(i, n) ab.push_back(a[i]);
    rep(i, n) ab.push_back(b[i]);

    compress(ab);

    vector<ll> a_(n), b_(n);
    rep(i, 2*n){
        if(i < n) a_[i] = ab[i];
        else b_[i-n] = ab[i];
    }

    a = a_;
    b = b_;

    // for(auto e: a) cout << e << " ";
    // cout << endl;
    // for(auto e: b) cout << e << " ";
    // cout << endl;

    vector<bitset<22000>> st_a(n), st_b(n);

    st_a[0].set(a[0]);
    st_b[0].set(b[0]);
    rep1(i, n){
        st_a[i] = st_a[i-1];
        st_a[i].set(a[i]);
    }
    rep1(i, n){
        st_b[i] = st_b[i-1];
        st_b[i].set(b[i]);
    }
    // cout << st_a.size() << endl;

    int q;
    cin >> q;

    rep(i, q){
        int x, y;
        cin >> x >> y;

        --x;
        --y;
        if(st_a[x] == st_b[y]){
            puts("Yes");
        }
        else{
            puts("No");
        }
    }

    


    return 0;
}