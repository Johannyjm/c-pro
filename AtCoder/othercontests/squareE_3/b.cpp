#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<vector<int>> refresh(vector<vector<int>> b, int h, int w){
    vector<vector<int>> ret(h, vector<int>(w, 0));
    rep(j, w){
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
    
    int h, w, k;
    cin >> h >> w >> k;

    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vector<vector<int>> board(h, vector<int>(w));
    rep(i, h) rep(j, w) board[i][j] = s[i][j] - '0';

    int res = 0;

    rep(si, h) rep(sj, w){

        vector<vector<int>> b = board;
        b[si][sj] = 0;

        b = refresh(b, h, w);

        int score = 0;
        int turn = 0;
        while(1){

            int sm = 0;
            rep(i, h){

                vector<pair<int, int>> vp;
                vp.push_back(make_pair(b[i][0], 1));

                rep1(j, w){
                    if(b[i][j] == vp.back().first) ++vp.back().second;
                    else{
                        vp.push_back(make_pair(b[i][j], 1));
                    }
                }

                // rep(j, vp.size()) cout << vp[j].first << ":" << vp[j].second << " ";
                // cout << endl;

                int ptr = 0;
                rep(j, vp.size()){
                    if(vp[j].second < k){
                        ptr += vp[j].second;
                    }
                    else{
                        sm += pow(2, turn)*(vp[j].first*vp[j].second);
                        for(int l = ptr; l < ptr+vp[j].second; ++l){
                            b[i][l] = 0;
                        }
                        ptr += vp[j].second;
                    }
                }
                // cout << endl;
                // rep(m, h){
                //     rep(o, w) cout << b[m][o] << " ";
                //     cout << endl;
                // }

            }

            if(sm == 0) break;
            else{
                score += sm;
                b = refresh(b, h, w);
            }

            ++turn;
        }

        res = max(res, score);
    }

    cout << res << endl;


    return 0;
}