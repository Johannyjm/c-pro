#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<vector<int>> refresh(vector<vector<int>> b, int h){
    vector<vector<int>> ret(h, vector<int>(5, 0));
    rep(j, 5){
        vector<int> nonzero;
        for(int i = h-1; i >= 0; --i){
            if(b[i][j] != 0) nonzero.push_back(b[i][j]);
        }

        rep(i, nonzero.size()){
            ret[h-i-1][j] = nonzero[i];
        }

    }

    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    while(1){
        int h;
        cin >> h;

        if(h == 0) break;

        vector<vector<int>> b(h, vector<int>(5));
        rep(i, h) rep(j, 5) cin >> b[i][j];

        int res = 0;
        while(1){

            int r_sm = 0;
            rep(i, h){

                int sm = 0;
                if(b[i][0]==b[i][1] && b[i][1]==b[i][2] && b[i][2]==b[i][3] && b[i][3]==b[i][4]){
                    sm += b[i][0] * 5;
                    rep(j, 5) b[i][j] = 0;
                }

                else if((b[i][0]==b[i][1] && b[i][1]==b[i][2] && b[i][2]==b[i][3]) || (b[i][1]==b[i][2] && b[i][2]==b[i][3] && b[i][3]==b[i][4])){
                    if(b[i][0] == b[i][1]){
                        sm += b[i][0] * 4;
                        rep(j, 4) b[i][j] = 0;
                    }
                    else{
                        sm += b[i][1] * 4;
                        rep1(j, 5) b[i][j] =0;
                    }
                }

                else if((b[i][0]==b[i][1] && b[i][1]==b[i][2]) || (b[i][1]==b[i][2] && b[i][2]==b[i][3]) || (b[i][2]==b[i][3] && b[i][3]==b[i][4])){
                    if(b[i][0] == b[i][1] && b[i][1]==b[i][2]){
                        sm += b[i][0] * 3;
                        rep(j, 3) b[i][j] = 0;
                    }
                    else if(b[i][2]==b[i][3] && b[i][3] == b[i][4]){
                        sm += b[i][2] * 3;
                        for(int j = 2; j < 5; ++j) b[i][j] = 0;
                    }
                    else{
                        sm += b[i][1] * 3;
                        rep1(j, 4) b[i][j] = 0;
                    }
                }

                r_sm += sm;

            }

            if(r_sm == 0) break;
            else{
                res += r_sm;

                // cout << endl;
                // rep(i, h){
                //     rep(j, 5) cout << b[i][j] << " ";
                //     cout << endl;
                // }

                b = refresh(b, h);
                // cout << endl;
                // rep(i, h){
                //     rep(j, 5) cout << b[i][j] << " ";
                //     cout << endl;
                // }
            }
        }

        cout << res << endl;
    }

    return 0;
}