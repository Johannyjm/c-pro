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

    vector<int> t(n), l__(n), r__(n);
    rep(i, n){
        cin >> t[i] >> l__[i] >> r__[i];
        // if(t[i] == 2) --r__[i];
        // if(t[i] == 3) ++l__[i];
        // if(t[i] == 4){
        //     --r__[i];
        //     ++l__[i];
        // }
    }

    vector<int> all = l__;
    rep(i, n){
        all.push_back(r__[i]);
    }

    // compress(l);
    // compress(r);
    compress(all);
    vector<int> l, r;
    rep(i, 2*n){
        if(i<n) l.push_back(all[i]);
        else r.push_back(all[i]);
    }

    int res = 0;
    rep1(i, n){
        int l_ = l[i];
        int r_ = r[i];
        rep(j, i){
            int pl = l[j];
            int pr = r[j];

            cout << l_ << " " << r_ << " " << pl << " " << pr << endl;
            if(pr<l_ || r_<pl) continue;
            // cout << i << " " << j << endl;
            ++res;
        }
    }

    cout << res << endl;

    return 0;
}