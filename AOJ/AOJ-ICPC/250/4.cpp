#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while(1){
        int n, m;
        cin >> n;
        if(n == 0) break;

        cin >> m;
        int x, y;
        cin >> x >> y;
        vector<vector<vector<int>>> origin(4, vector<vector<int>>(m-1, vector<int>(2)));
        rep(i, m-1){
            int nx, ny;
            cin >> nx >> ny;
            origin[0][i][0] = nx - x;
            origin[0][i][1] = ny - y;
            x = nx;
            y = ny;
        }
        rep(i, m-1){
            if(i%2 == 1){
                origin[1][i][0] = -origin[0][i][1];
                origin[1][i][1] = -origin[0][i][0];
            }
            else{
                origin[1][i][0] = origin[0][i][1];
                origin[1][i][1] = origin[0][i][0];
            }
        }
        rep(i, m-1){
            origin[2][i][0] = -origin[0][i][0];
            origin[2][i][1] = -origin[0][i][1];
            origin[3][i][0] = -origin[1][i][0];
            origin[3][i][1] = -origin[1][i][1];
        }


        rep(i, n){
            cin >> m;
            cin >> x >> y;
            vector<vector<int>> cand(m-1, vector<int>(2));
            rep(j, m-1){
                int nx, ny;
                cin >> nx >> ny;
                cand[j][0] = nx - x;
                cand[j][1] = ny - y;
                x = nx;
                y = ny;
            }
            bool flg = false;
            rep(j, 4){
                if(origin[j] == cand) flg = true;
            }
            reverse(cand.begin(), cand.end());
            rep(j, 4){
                if(origin[j] == cand) flg = true;
            }

            if(flg) cout << i+1 << endl;

        }

        cout << "+++++" << endl;

    }

    return 0;
}