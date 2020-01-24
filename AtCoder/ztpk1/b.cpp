#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> bucket_a(26, 0);
    vector<int> bucket_b(26, 0);
    vector<int> bucket_c(26, 0);

    rep(i, n){
        ++bucket_a[a[i] - 'a'];
        ++bucket_b[b[i] - 'a'];
        ++bucket_c[c[i] - 'a'];
    }

    // sort(a.begin(), a.end(), greater<int>());
    // sort(b.begin(), b.end(), greater<int>());
    // sort(c.begin(), c.end(), greater<int>());

    int res = 0;
    rep(i, 26){
        res += min(bucket_a[i], min(bucket_b[i], bucket_c[i]));
    }

    cout << res << endl;


    return 0;
}