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

    map<int, int> cnt;
    int res = 0;
    rep(i, n){
        if(cnt[a[i]] > 0) ++res;
        ++cnt[a[i]];
    }
    cout << res << endl;

    return 0;
}