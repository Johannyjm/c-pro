#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int max_len = -1;
    int sum_len = 0;

    rep(i, n){
        int l;
        cin >> l;

        max_len = max(max_len, l);
        sum_len += l;
    }

    sum_len -= max_len;

    if(max_len >= sum_len) puts("No");
    else puts("Yes");
}