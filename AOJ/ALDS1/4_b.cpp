#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> s(n);
    rep(i, n) cin >> s[i];

    int q;
    cin >> q;
    vector<int> t(q);
    rep(i, q) cin >> t[i];

    int res = 0;
    rep(i, q){
        int target = t[i];

        int l = 0;
        int r = n-1;

        if(target == s[l] || target == s[r]){
            ++res;
            continue;
        }


        while(abs(r-l) > 1){
            int m = (l + r) / 2;

            if(target == s[m]){
                ++res;
                break;
            }

            if(target < s[m]) r = m;
            if(target > s[m]) l = m;
        }

    }

    cout << res << endl;

    return 0;
}