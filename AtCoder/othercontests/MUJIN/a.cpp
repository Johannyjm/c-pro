#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    char c;
    cin >> c;

    if(c=='O' || c=='P' || c=='K' || c=='L') puts("Right");
    else puts("Left");

    return 0;
}