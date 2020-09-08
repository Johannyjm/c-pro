#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;

    int prev;
    cin >> prev;
    int res = 0;
    for(int i = 1; i < n; ++i){
        int a;
        cin >> a;

        if(a<prev+t) res += a-prev;
        else res += t;

        prev = a;
    }
    cout << res+t << endl;
}