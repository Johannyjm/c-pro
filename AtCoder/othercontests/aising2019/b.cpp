#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;

    int one = 0;
    int two = 0;
    int three = 0;

    rep(i, n){
        int p;
        cin >> p;

        if(p <= a) ++one;
        if(a<p && p<=b) ++two;
        if(b < p) ++three;
    }

    cout << min(one, min(two, three)) << endl;

    return 0;
}