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

    sort(a.begin(), a.end(), greater<int>());

    ll res = a[0];
    int l = 1;
    int idx = 1;
    while(l != n-1){
        res += a[idx];
        l++;
        if(l == n-1) break;
        res += a[idx];
        l++;
        ++idx;
    }

    cout << res << endl;

    return 0;
}