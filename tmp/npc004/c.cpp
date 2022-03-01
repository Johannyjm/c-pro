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

    int n = 4;
    vector<vector<int>> g(n);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    unordered_map<int, int> cnt;
    rep(i, n){
        ++cnt[(int)g[i].size()];
    }

    if(cnt[1] == 2 && cnt[2] == 2) puts("YES");
    else puts("NO");


    return 0;
}