#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int num_rates[9] = {0};
    rep(i, n){
        int a;
        cin >> a;
        ++num_rates[min(8, a/400)];
    }
    int res = 0;
    rep(i, 8){
        if(num_rates[i]>0)++res;
    }
    if(res) cout << res << " " << res + num_rates[8] << endl;
    else cout << 1 << " " << num_rates[8] << endl;
}