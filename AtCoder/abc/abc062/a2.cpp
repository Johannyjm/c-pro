#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;

    int group[12] = {0, 2, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0};

    if(group[x-1] == group[y-1]) puts("Yes");
    else puts("No");
}