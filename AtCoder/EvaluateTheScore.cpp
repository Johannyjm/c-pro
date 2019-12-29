#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    if(n == 100) puts("Perfect");
    else if(90<=n && n<=99) puts("Great");
    else if(60<=n && n<=89) puts("Good");
    else puts("Bad");

    return 0;
}