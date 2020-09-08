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

    vector<int> num(n, 1);
    vector<bool> cand(n, false);
    cand[0] = true;
    int ptr = 0;
    rep(i, m){
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        --num[x];
        ++num[y];
        if(cand[x]) {
            cand[y] = true;
            if(num[x]==0) cand[x] = false;
        }
    }

    int res = 0;
    rep(i, n){
        if(num[i] && cand[i]) ++res;
    }

    cout << res << endl;

    return 0;
}