#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int l, r;
    cin >> l >> r;

    vector<int> bucketl(50, 0);
    vector<int> bucketr(50, 0);

    rep(i, l){
        int L;
        cin >> L;
        ++bucketl[L];
    }

    rep(i, r){
        int R;
        cin >> R;
        ++bucketr[R];
    }

    int res = 0;
    rep(i, 50){
        res += min(bucketl[i], bucketr[i]);
    }

    cout << res << endl;

    return 0;
}