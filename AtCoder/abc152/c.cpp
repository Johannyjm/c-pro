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

    int base;
    cin >> base;
    int res = 1;

    rep1(i, n){
        int p;
        cin >> p;

        if(p<base){
            ++res;
            base = p;
        }
    }
    cout << res << endl;

    return 0;
}