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

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> ba(m);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        ba[i] = {b, a};
    }

    sort(ba.begin(), ba.end());

    fenwick_tree<int> broken(n-1);
    int res = 0;
    rep(i, m){
        int l = ba[i].second;
        int r = ba[i].first;

        if(broken.sum(l, r) > 0) continue;

        broken.add(r-1, 1);
        ++res;
    }

    cout << res << endl;

    return 0;
}