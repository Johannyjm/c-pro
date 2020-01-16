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

    vector<int> a(n);
    int a_sum = 0;
    rep(i, n){
        cin >> a[i];
        a_sum += a[i];
    }
    
    int ave = a_sum / n;
    int res = 0;
    rep(i, n) {
        res += (ave - a[i]) * (ave - a[i]);
    }

    int ave1 = ave + 1;
    int res1 = 0;
    rep(i, n){
        res1 += (ave1 - a[i]) * (ave1 - a[i]);
    }

    cout << min(res, res1) << endl;

    return 0;
}