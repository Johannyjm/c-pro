#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int d, g;
    cin >> d >> g;
    vector<int> p(d), c(d);
    for(int i = 0; i < d; ++i) cin >> p[i] >> c[i];

    const int INF = 1001001001;
    vector<vector<int>> dp(d+1, vector<int>(5500000, INF));
    int mx_s = 0;
    for(int score = 1; score <= d; ++score){
        if(score == 1){
            for(int j = 1; j <= p[score-1]-1; ++j){
                dp[score][score*j] = j;
            }
            
            mx_s = score*p[score-1] + c[score-1]/100;
            dp[score][mx_s] = p[score-1];
            continue;
        }

        for(int j = 0; j <= p[score-1]-1; ++j){
            dp[score][score*j] = min({dp[score][score*j], dp[score-1][score*j], j});
            for(int k = 1; k <= 400000; ++k){
                dp[score][k+score*j] = min({dp[score][k+score*j], dp[score-1][k+score*j], dp[score-1][k]+j});
            }
        }

        int rest = score*p[score-1] + c[score-1]/100;

        dp[score][rest] = min(dp[score][rest], p[score-1]);
        for(int k = 1; k <= 400000; ++k){
           dp[score][k+rest] = min({dp[score][k+rest], dp[score-1][k+rest], dp[score-1][k] + p[score-1]});
        }

        mx_s = max(mx_s, rest);
        

//        for(int j = 1; j < 5500000; ++j){
//            dp[score][j] = min(dp[score][j], dp[score-1][j]);
//            if(j%score == 0){
//                if(j/score == p[score-1]){
//                    dp[score][score*p[score-1]+c[score-1]/100] = p[score-1];
//                    break;
//                }
//                else dp[score][j] = min(dp[score][j], j/score);
//            }

//            dp[score][j] = min({dp[score][j], dp[score][j-score]+1, dp[score-1][j-score]+1});
//        }
    }
    
//    for(int score = 1; score <= 5; ++score){
//        for(int i = 0; i < 259; ++i){
//            cout << dp[score][i] << " ";
//        }
//        cout << endl;
//    }

    int res = INF;
    for(int i = g/100; i < 5500000; ++i){
        res = min(res, dp[d][i]);
    }

    cout << res << endl;

    return 0;
}
