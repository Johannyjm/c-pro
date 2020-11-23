#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    vector<ll> pre, post;
    rep(i, n){
        if(i < (n+1)/2) pre.push_back(a[i]);
        else post.push_back(a[i]);
    }

    // for(auto e: pre) cout << e << " ";
    // cout << endl;
    // for(auto e: post) cout << e << " ";
    // cout << endl;

    unordered_set<ll> sm1;
    vector<ll> sm2;
    int n1 = pre.size();
    int n2 = post.size();

    rep(i, 1<<n1){
        vector<int> use(n1, 0);
        rep(j, n1){
            if(i & (1<<j)){
                use[j] = 1;
            }
        }

        ll sm = 0;
        rep(j, n1){
            if(use[j]) sm += pre[j];
        }

        sm1.insert(sm);
    }

    rep(i, 1<<n2){
        vector<int> use(n2, 0);
        rep(j, n2){
            if(i & (1<<j)){
                use[j] = 1;
            }
        }

        ll sm = 0;
        rep(j, n2){
            if(use[j]) sm += post[j];
        }

        sm2.push_back(sm);
    }

    // for(auto e: sm1) cout << e << " ";
    // cout << endl;
    // for(auto e: sm2) cout << e << " ";
    // cout << endl;

    sort(sm2.begin(), sm2.end());

    ll res = 0;
    for(auto e: sm1){
        if(e > t) continue;

        int idx = lower_bound(sm2.begin(), sm2.end(), t-e) - sm2.begin();
        ll val = sm2[idx]+e;
        if(idx == 0) val = e;
        if(idx == (int)sm2.size()) val = sm2.back()+e;

        if(val > t){
            if(idx == 0) val = 0;
            else val = sm2[idx-1] + e;
        }
            

        res = max(res, val);
        // cout << e << " " << idx << " " << val << " " << res << endl;
    }

    cout << res << endl;



    return 0;
}