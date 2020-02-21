#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    int res = 1;
    int dist = 0;
    rep(i, n){
        int l;
        cin >> l;

        dist += l;
        if(dist > x){
            cout << res << endl;
            return 0;
        }
        ++res;
    }

    cout << res << endl;

    return 0;
}