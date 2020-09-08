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
    vector<int> o(n), p(n), q(n);

    rep(i, n){
        o[i] = i+1;
        cin >> p[i];
    }
    rep(i, n) cin >> q[i];

    int a, b;
    int cnt = 1;
    do{
        bool same_p = true;
        rep(i, n) {
            if(o[i] != p[i]) same_p = false;
        }
        if(same_p) a = cnt;

        bool same_q = true;
        rep(i, n) {
            if(o[i] != q[i]) same_q = false;
        }
        if(same_q) b = cnt;

        ++cnt;
    } while(next_permutation(o.begin(), o.end()));

    cout << abs(a - b) << endl;

    return 0;
}