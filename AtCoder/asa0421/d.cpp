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

    int prev;
    cin >> prev;
    int st = 0;
    int stmp = 0;
    int tu = 0;
    int res = 0;
    rep1(i, n){
        int curr;
        cin >> curr;

        if(curr > prev) {
            ++st;
            stmp = st;
            tu = 0;
        }
        else{
            ++tu;
            st = 0;
            res = max(res, stmp+tu+1);
        }

        prev = curr;
    }

    if(n == 1) res = 1;
    if(st) res = max(res, st+1);

    cout << res << endl;

    return 0;
}