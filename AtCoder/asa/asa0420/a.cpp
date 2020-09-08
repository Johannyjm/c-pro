#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    rep(i, m){
        if(n <= a) n += b;

        int c;
        cin >> c;

        n -= c;
        if(n < 0) {
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << "complete" << endl;

    return 0;
}