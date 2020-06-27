#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<vector<int>> refresh(vector<vector<int>> b, int h){
    rep(j, 5){
        for(int i = h-1; i >= 0; --i){
            if(b[i][j] == 0){
                for(int k = i; k >= 0; --k){
                    if(k == 0) b[k][j] = 0;
                    else b[k][j] = b[k-1][j];
                }
            }
        }
    }

    return b;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h;
    cin >> h;
    vector<vector<int>> a(h, vector<int>(5));
    rep(i, h) rep(j, 5) cin >> a[i][j];


    vector<vector<int>> b = refresh(a, h);

    cout << endl;
    rep(i, h){
        rep(j, 5) cout << b[i][j] << " ";
        cout << endl;
    }

    return 0;


    while(1){
        int h;
        cin >> h;

        if(h == 0) break;

        vector<vector<int>> b(h, vector<int>(5));
        rep(i, h) rep(j, 5) cin >> b[i][j];

        int res_prev = 0;
        while(1){
            int res = 0;
            rep(i, h){
                vector<pair<int, int>> p;
                p.push_back(make_pair(b[i][0], 1));

                rep1(j, 5){
                    if(b[i][j] == p.back().first) ++p.back().second;
                    else p.push_back(make_pair(b[i][j], 1));
                }

                bool dropflg = false;
                int dropnum;
                for(auto elem: p){
                    if(elem.second >= 3){
                        dropflg = true;
                        res += elem.first * elem.second;
                        dropnum = elem.first;
                    }
                }

                if(dropflg){
                    if(dropnum == 3){
                        if(b[i][0] == b[i][1]){
                            rep(j, 3) b[i][j] = 0;
                        }
                        else{
                            for(int j = 2; j < 5; ++j) b[i][j] = 0;
                        }
                    }
                    else{
                        rep(j, 5){
                            if(b[i][j] == dropnum) b[i][j] = 0;
                        }
                    }

                }

                refresh(b, h);

            }

            if(res == res_prev) break;
            else res_prev = res;

        }

        cout << res_prev << endl;
    }

    return 0;
}