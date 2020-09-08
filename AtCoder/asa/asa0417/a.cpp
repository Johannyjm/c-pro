#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, l;
    cin >> n >> l;

    int full = 0;
    for(int i = l; i < n+l; ++i) full += i;

    int res;
    int min_d = 1001001001;
    for(int i = l; i < n+l; ++i){
        int sub = full - i;
        if(abs(full - sub) < min_d){
            res = sub;
            min_d = abs(full - sub);
        }
    }

    cout << res << endl;
}