#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const int di[] = {0, 1, 1, 0, -1, -1};
const int djo[] = {1, 1, 0, -1, 0, 1};
const int dje[] = {1, 0, -1, -1, -1, 0};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int w, h;
    cin >> w >> h;

    vector<vector<int>> c(h+2, vector<int>(w+2, 0));
    rep1(i, h+1) rep1(j, w+1) cin >> c[i][j];


    c[0][0] = 2; // outside
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        rep(dir, 6){
            int ni = i + di[dir];
            int nj;
            if(i%2) nj = j + djo[dir];
            else nj = j + dje[dir];

            if(ni<0 || ni>=h+2 || nj<0|| nj>=w+2) continue;
            if(c[ni][nj] != 0) continue;

            c[ni][nj] = 2;
            q.push(make_pair(ni, nj));
        }
    }

    int res = 0;
    rep(i, h+2){
        rep(j, w+2){
            if(c[i][j]==1){
                int sum = 0;
                rep(dir, 6){
                    int ni = i + di[dir];
                    int nj;
                    if(i%2) nj = j + djo[dir];
                    else nj = j + dje[dir];

                    if(ni<0 || ni>=h+2 || nj<0|| nj>=w+2) continue;

                    if(c[ni][nj] == 2) ++sum;               
                }
                res += sum;
            }
        }
    }

    cout << res << endl;

    return 0;
}