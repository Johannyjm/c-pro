#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int w, h;
    cin >> w >> h;

    vector<vector<int>> c(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> c[i][j];

    vector<vector<int>> hexed((h+1)*2, vector<int>(w+1, 9));
    rep(i, w) hexed[0][i] = c[0][i];
    rep(i, w) hexed[(h+1)*2-1][i] = c[h-1][i];
    rep1(i, (h+1)*2 - 1) hexed[i][0] = c[(i-1)/2][0];
    rep1(i, (h+1)*2 - 1) {
        if(i%2) hexed[i][w] = c[(i-1)/2][w-1];
        else hexed[i][w-1] = c[(i-1)/2][w-1];
    }
    


    rep1(i, (h+1)*2-1){
        rep1(j, w){
            if(i%2){
                if(hexed[i-1][w]+hexed[i-1][w-1] == 1) hexed[i][j] = 1;
                else hexed[i][j] = 0;
            }
            else{
                if(hexed[i-1][w]+hexed[i-1][w-1] == 1) hexed[i][j] = 1;
                else hexed[i][j] = 0;
            }
        }
    }

    rep(i, (h+1)*2){
        rep(j, w+1){
            cout << hexed[i][j] << " ";
        }
        cout << endl;
    }

    // rep(i, (h+1)*2){
    //     rep(j, w+1){
    //         if(i%2==0){
    //             if(j==w) continue;
    //             hexed[i][j] = c[i/2][j];
    //         }
    //         else{
    //             if(j==0) continue;
    //             if()
    //         }
    //     }
    // }

    return 0;
}