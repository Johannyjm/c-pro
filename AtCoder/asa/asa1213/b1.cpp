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
    int res = 1;
    int mx;
    cin >> mx;
    rep1(i, n){
        int h;
        cin >> h;
        if(h >= mx) ++res;
        mx = max(mx, h);
    }

    cout << res << endl;

    return 0;
}