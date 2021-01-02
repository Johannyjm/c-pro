#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> sm(4, vector<int>(n+1, 0));
    rep1(i, n+1){
        rep(j, 4){
            sm[j][i] += sm[j][i-1];
        }

        if(s[i-1] == 'A') ++sm[0][i];
        if(s[i-1] == 'T') ++sm[1][i];
        if(s[i-1] == 'G') ++sm[2][i];
        if(s[i-1] == 'C') ++sm[3][i];
        
    }

    // rep(j, 4){
    //     rep(i, n+1) cout << sm[j][i] << " ";
    //     cout << endl;
    // }

    int res = 0;
    for(int i = 2; i <= n; i += 2){
        rep(j, n-i+1){
            int l = j;
            int r = j + i;

            int A = sm[0][r] - sm[0][l];
            int T = sm[1][r] - sm[1][l];
            int G = sm[2][r] - sm[2][l];
            int C = sm[3][r] - sm[3][l];
            // cout << l << " " << r << " " << A << " " << T << " " << G << " " << C << endl;
            if(A==T && G==C) ++res;

        }
    }

    cout << res << endl;

    return 0;
}