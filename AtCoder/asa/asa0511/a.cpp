#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> t(n);
    rep(i, n) cin >> t[i];

    int sm = t[0] + t[1] + t[2];
    if(sm < k){
        cout << 3 << endl;
        return 0;
    }
    for(int i = 3; i < n; ++i){
        sm -= t[i-3];
        sm += t[i];

        if(sm < k){
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}