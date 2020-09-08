#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> sum(3, vector<int>(n, 0));
    rep(i, n){
        if(i!=0) {
            rep(j, 3) sum[j][i] = sum[j][i-1];
        }
        if(s[i] == 'R') ++sum[0][i];
        if(s[i] == 'G') ++sum[1][i];
        if(s[i] == 'B') ++sum[2][i];
    }

    rep(i, 3){
        rep(j, n) cout << sum[i][j] << " ";
        cout << endl;
    }

    return 0;
}