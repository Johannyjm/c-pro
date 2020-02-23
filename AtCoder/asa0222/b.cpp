#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> b(n);
    rep(i, n+1) cin >> a[i];
    rep(i, n) cin >> b[i];

    int res = 0;
    rep(i, n){
        if(a[i]>= b[i]){
            res += b[i];
        }
        else{
            res += a[i];
            if(a[i+1]-(b[i] - a[i])>0){
                a[i+1] -= (b[i] - a[i]);
                res += (b[i] - a[i]);
            }
            else{
                res += a[i+1];
                a[i+1] = 0;
            }
        }
    }

    cout << res << endl;

    return 0;
}