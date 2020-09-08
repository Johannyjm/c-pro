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
    map<pair<int, int>, int> cand;

    int res = 0;
    rep(i, n){
        int a;
        cin >> a;
        --a;

        if(cand[make_pair(min(i, a), max(i, a))] > 0){
            ++res;
            --cand[make_pair(min(i, a), max(i, a))];
        }
        else ++cand[make_pair(min(i, a), max(i, a))];
    }

    cout << res << endl;

    return 0;
}