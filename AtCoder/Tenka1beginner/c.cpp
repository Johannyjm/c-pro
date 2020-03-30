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
    string s;
    cin >> s;

    vector<int> num_black(n, 0);
    if(s[0] == '#') num_black[0] = 1;

    rep1(i, n){
        if(s[i] == '#') num_black[i] = num_black[i-1] + 1;
        else num_black[i] = num_black[i-1];
    }

    int res = min(n-num_black[n-1], num_black[n-1]);
    rep1(i, n){
        res = min(res, n-i-(num_black[n-1]-num_black[i-1])+num_black[i-1]);
    }

    cout << res << endl;

    return 0;
}