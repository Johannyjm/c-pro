#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    unordered_map<int, vector<int>> cnt;
    rep(i, n){
        cin >> a[i];
        cnt[a[i]].push_back(i+1);
    }

    rep(_, q){
        int x, k;
        cin >> x >> k;
        --k;

        if((int)cnt[x].size() <= k) cout << -1 << "\n";
        else cout << cnt[x][k] << "\n";
    }

    return 0;
}