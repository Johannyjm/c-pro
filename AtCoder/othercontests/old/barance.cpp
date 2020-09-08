#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int w[n];
    int all;

    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        all += w[i];
    }

    int ans = 1e9;
    for (int i = 1; i < n; ++i){
        int left = 0;
        for (int j = 0; j < i; ++j){
            left += w[j];
        }
        int right = all - left;

        ans = min(ans, abs(left-right));
    }
    cout << ans << endl;
}