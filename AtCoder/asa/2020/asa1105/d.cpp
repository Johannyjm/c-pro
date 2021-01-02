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

    vector<int> muls(1100000);
    map<int, int> cnt;
    rep(i, n){
        if(cnt[a[i]] > 1) continue;
        ++cnt[a[i]];
        for(int j = a[i]; j < 1100000; j += a[i]){
            ++muls[j];
        }
    }
    // rep(i, 100) cout << i << ":" << muls[i] << " ";
    // cout << endl;

    int res = 0;
    rep(i, n){
        if(muls[a[i]] == 1) ++res;
    }

    cout << res << endl;

    return 0;
}