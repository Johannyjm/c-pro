#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int r;
    cin >> r;

    if(r<1200) puts("ABC");
    else if(1200<=r && r<2800) puts("ARC");
    else puts("AGC");
}