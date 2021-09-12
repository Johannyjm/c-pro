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
    vector<int> b(n-1);
    rep(i, n-1) cin >> b[i];

    if(n == 2){
        cout << b[0] * 2 << endl;
        return 0;
    }

    vector<int> a(n);
    a[0] = b[0];
    rep1(i, n-1){
        a[i] = min(b[i], b[i-1]);
    }
    a[n-1] = b[n-2];

    int res = 0;
    rep(i, n) res += a[i];


    cout << res << endl;

    return 0;
}