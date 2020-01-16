#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pair<int, int>> height_idx(n);
    rep(i, n){
        int a;
        cin >> a;
        height_idx[i] = make_pair(a, i+1);
    }

    sort(height_idx.begin(), height_idx.end());

    for(int i = n-1; i >= 0; --i) {
        cout << height_idx[i].second << endl;
    }

    return 0;
}