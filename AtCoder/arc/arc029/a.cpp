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
    vector<int> t(n);
    rep(i, n) cin >> t[i];

    int res = 201;
    for(int i = 0; i < (1 << n); ++i){

        int one = 0;
        int two = 0;
        for(int j = 0; j < n; ++j){
            if(i & (1 << j)) two += t[j];
            else one += t[j];
        }

        res = min(res, max(one, two));
    }

    cout << res << endl;


    return 0;
}