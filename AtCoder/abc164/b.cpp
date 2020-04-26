#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    while(1){
        c -= b;
        if(c <= 0) {
            puts("Yes");
            return 0;
        }
        a -= d;
        if(a <= 0){
            puts("No");
            return 0;
        }
    }

    return 0;
}