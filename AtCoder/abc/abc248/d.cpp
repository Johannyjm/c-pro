#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> indices(n);
    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
        --a[i];
        indices[a[i]].push_back(i);
    }

    int q;
    cin >> q;

    while(q--){
        int l, r, x;
        cin >> l >> r >> x;
        --l;
        --r;
        --x;

        if(indices[x].size() == 0){
            cout << 0 << "\n";
            continue;
        }

        int res = upper_bound(indices[x].begin(), indices[x].end(), r) - lower_bound(indices[x].begin(), indices[x].end(), l);

        cout << res << endl;
    }

    return 0;
}