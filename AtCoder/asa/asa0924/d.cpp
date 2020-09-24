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
    int mx = -1;
    rep(i, n){
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    vector<int> b(mx+10, 0);
    rep(i, n){
        int d = a[i];
        for(int j = d; j < mx+10; j += d) ++b[j];
    }

    int res = 0;
    rep(i, n){
        if(b[a[i]] == 1) ++res;
    }

    cout << res << endl;

    return 0;
}