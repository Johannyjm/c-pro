#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a;
    cin >> a;

    rep1(i, 101){
        if(i*i*i == a){
            puts("YES");
            return 0;
        }
    }

    puts("NO");

    return 0;
}