#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> d(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> d[i][j];

    vector<vector<int>> s(n, vector<int>(n, 0));
    s[0][0] = d[0][0];
    rep1(i, n){
        s[0][i] = s[0][i-1] + d[0][i];
        s[i][0] = s[i-1][0] + d[i][0];
    }

    rep1(i, n) {
        int sm = d[i][0];
        rep1(j, n){
            sm += d[i][j];
            s[i][j] = s[i-1][j] + sm;
        }
    }

    // rep(i, n){
    //     rep(j, n) cout << s[i][j] << " ";
    //     cout << endl;
    // }

    map<int, int> mp;
    rep(i, n){
        rep(j, n){
            for(int k = i; k < n; ++k){
                for(int l = j; l < n; ++l){
                    int num = (k-i+1) * (l-j+1);
                    int sm = s[k][l];
                    
                    if(i!=0 || j!=0){
                        if(i!=0 && j!=0){
                            sm = sm - s[i-1][l] - s[k][j-1] + s[i-1][j-1];
                        }
                        if(i == 0){
                            sm -= s[k][j-1];
                        }
                        if(j == 0){
                            sm -= s[i-1][l];
                        }
                    }

                    mp[num] = max(mp[num], sm);
                }
            }
        }
    }

    int q;
    cin >> q;
    rep(_, q){
        int p;
        cin >> p;

        int res = -1;
        rep(i, p+1) res = max(res, mp[i]);
        cout << res << "\n";
    }


    return 0;
}