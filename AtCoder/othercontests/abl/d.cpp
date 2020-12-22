#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

int op(int a, int b) { return max(a, b); }

int e() { return -1; }

int target;

bool f(int v) { return v < target; }

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<int>> dp(n);
    int ptr = 0;
    dp[ptr].push_back(a[0]);

    vector<int> s(n, -1);
    segtree<int, op, e> seg(s);
    seg.set(0, a[0]);
    rep1(i, n){
        seg.set(i, a[i]);
        if(abs(dp[ptr].back()-a[i]) <= k) dp[ptr].push_back(a[i]);
        else{
            target = a[i]-3;
            int idx1 = seg.max_right<f>(i);
            target = a[i]+3;
            int idx2 = seg.min_left<f>(i);

            int idx = max(idx1, idx2);
            dp[ptr = idx].push_back(a[i]);
        }
    }

    rep(i, n){
        for(auto e: dp[i]) cout << e << " ";
        cout << endl;
    }


    return 0;
}