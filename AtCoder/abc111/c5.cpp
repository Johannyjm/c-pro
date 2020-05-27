#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<pair<int, int>> cnt(10010);
    rep(i, 10010) cnt[i] = make_pair(0, i);
    rep(i, n){
        int aa;
        cin >> aa;

        a[i] = aa;
        ++cnt[aa].first;
    }

    sort(cnt.begin(), cnt.end(), greater<pair<int, int>>());

    int zig = cnt[0].second;
    int zag = cnt[1].second;
    
    if(cnt[1].first == 0){
        cout << n/2 << endl;
        return 0;
    }

    int res = 1001001001;
    // zigzagzigzag...
    int sm = 0;
    rep(i, n){
        if(i%2 == 0){
            if(a[i] != zig) ++sm;
        }
        else{
            if(a[i] != zag) ++sm;
        }
    }
    res = min(res, sm);

    // zagzigzagzig...
    sm = 0;
    rep(i, n){
        if(i%2 == 0){
            if(a[i] != zag) ++sm;
        }
        else{
            if(a[i] != zig) ++sm;
        }
    }

    res = min(res, sm);

    cout << res << endl;

    return 0;
}