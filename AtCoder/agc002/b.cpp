#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<bool> is_possible(n, false);
    vector<int> num(n, 1);
    is_possible[0] = true;

    rep(i, m){
        int x, y;
        cin >> x >> y;
        --x;
        --y;

        --num[x];
        ++num[y];
        if(is_possible[x]){
            is_possible[y] = true;
            if(num[x]==0) is_possible[x] = false;
        }
    }

    int res = 0;
    rep(i, n){
        res += is_possible[i];
    }
    
    cout << res << endl;

    return 0;
}