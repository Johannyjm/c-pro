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

    pair<int, int> rl[n];
    rep(i, n){
        int x, l;
        cin >> x >> l;

        rl[i] = make_pair(x+l, x-l);
    }

    sort(rl, rl+n);

    int pr = rl[0].first;
    //int pl = rl[0].second;
    int res = 1;
    rep1(i, n){
        int r = rl[i].first;
        int l = rl[i].second;

        if(l >= pr) {
            ++res;
            pr = r;
        }
    }

    cout << res << endl;

    return 0;
}