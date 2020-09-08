#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    rep(z, m/4 + 1){
        int y = m - 2*n - 2*z;
        int x = n - y - z;

        if(x >= 0 && y >= 0){
            cout << x << " " << y << " " << z << endl;
            return 0;
        }
    }

    
    cout << "-1 -1 -1" << endl;

    return 0;
}