#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    rep(_, t){
        int n;
        cin >> n;

        vector<vector<ll>> a(n, vector<ll>(60, 0));
        rep(i, n){
            ll num;
            cin >> num;
            ll d = 0;
            while(num){
                if(num%2) a[i][d] = 1;
                num /= 2;
                ++d;
            }
        }
    
        rep(i, n) {
            rep(j, 60) cout << a[i][j];
            cout << endl;
        }

        string s;
        cin >> s;

        ll xorsum = 0;
        // rep(i, n) xorsum ^= a[i];
        // rep(i, n) cout << (xorsum^a[i]) << endl;

    }

    return 0;
}