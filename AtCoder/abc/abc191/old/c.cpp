#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    rep(i, h) cin >> s[i];


    int l = -1;
    int r = -1;
    int u = -1;
    int d = -1;
    rep(i, h) rep(j, w){
        if(l==-1 && s[i][j] == '#') l = j;
        if(u==-1 && s[i][j] == '#') u = i;
        if(s[i][j] == '#'){
            r = j;
            d = i;
        }
    }

    cout << l << " " << r << " " << u << " " << d << endl;

    int res = 4;
    for(int i = u; i <= d; ++i){
        for(int j = l; j <= r; ++j){
            if(s[i][j] == '.'){
                
            }
        }
    }

    // int si = -1;
    // int sj = -1;
    // rep(i, h) rep(j, w){
    //     rep(dir, 4){
    //         int ny = i + dy[dir];
    //         int nx = j + dx[dir];
    //         if(ny<0 || ny>=h || nx<0 || nx>=w) continue;

    //         if(si==-1 && sj==-1 && s[ny][nx] == '#'){
    //             si = i;
    //             sj = j;
    //         }
    //     }
    // }



    return 0;
}