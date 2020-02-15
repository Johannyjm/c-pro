#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n = 6;
    vector<int> e(n);
    rep(i, n) cin >> e[i];
    int b;
    cin >> b;

    int cnt = 0;
    int wn = 0;

    rep(i, n){
        int l;
        cin >> l;

        bool flg = true;
        rep(j, n){
            if(e[j] == l){
                ++cnt;
                flg = false;
                break;
            }
        }
        if(flg) wn = l;
    }


    int res;
    if(cnt < 3) res = 0;
    else if(cnt == 3) res = 5;
    else if(cnt == 4) res = 4;
    else if(cnt == 5) {
        if(wn == b)res = 2;
        else res = 3;
    }
    else res = 1;

    cout << res << endl;

    return 0;
}