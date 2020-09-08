#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));
    vector<int> black(c, 0);
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            cin >> a[i][j];
            black[j] += a[i][j];
        }
    }

    int res = 0;
    for(int i = 0; i < c; ++ i){
        res += max(black[i], r - black[i]);
    }

    for(int i = 0; i < (1<<r); ++i){
        vector<int> black_diff(c, 0);
        for(int j = 0; j < r; ++j){

            if(i & (1<<j)){
                for(int k = 0; k < c; ++k){
                    black_diff[k] += a[j][k] ? -1: 1;
                }
            }
        }

        int sum = 0;
        for(int j = 0; j < c; ++j){
            sum += max(black[j]+black_diff[j], r-(black[j]+black_diff[j]));
        }
        
        res = max(res, sum);
    }

    cout << res << endl;

    return 0;
}