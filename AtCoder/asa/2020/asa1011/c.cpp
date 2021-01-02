#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int res = 1001001001;
    for(int i = -100; i <= 100; ++i){
        int sm = 0;
        for(int j = 0; j < n; ++j){
            sm += (a[j] - i) * (a[j] - i);
        }

        res = min(res, sm);
    }

    cout << res << endl;

    return 0;
}