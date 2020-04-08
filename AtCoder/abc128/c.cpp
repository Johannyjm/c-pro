#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> s(m);
    vector<int> k(m);
    rep(i, m){
        cin >> k[i];
        vector<int> sk(k[i]);
        rep(j, k[i]) cin >> sk[j];

        s[i] = sk;
    }
    vector<int> p(m);
    rep(i, m) cin >> p[i];

    int res = 0;
    rep(i, 1<<n){
        vector<int> on(n, 0);
        rep(j, n){
            if(i & (1<<j)) on[j] = 1;
        }

        bool all_on = true;
        rep(j, m){
            int on_num = 0;
            rep(l, k[j]){
                if(on[s[j][l]-1]) ++on_num;
            }

            if(on_num%2 != p[j]) {
                all_on = false;
                break;
            }
        }
        
        if(all_on) ++res;
    }

    cout << res << endl;

    return 0;
}