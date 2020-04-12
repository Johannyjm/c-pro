#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const int dx[] = {1, 1, -1, -1};
const int dy[] = {-1, 1, 1, -1};

bool check(vector<int> loc){
    rep(i, 8){
        int x = loc[i];
        int y = i;
        rep(dir, 4){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            while(0<=nx && nx<8 && 0<=ny && ny<8){
                
                if(loc[ny] == nx) return false;

                nx += dx[dir];
                ny += dy[dir];
            }
        }
    }

    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int k;
    cin >> k;

    vector<int> r(k), c(k);
    rep(i, k) cin >> r[i] >> c[i];

    vector<int> loc(8);
    rep(i, 8) loc[i] = i;

    do{
        bool verified = true;
        rep(i, k){
            if(loc[r[i]] != c[i]) verified = false;
        }
        if(!verified) continue;

        if(check(loc)) break;


    } while(next_permutation(loc.begin(), loc.end()));

    rep(i, 8){
        rep(j, 8){
            if(loc[i] == j) cout << 'Q';
            else cout << '.';
        }
        cout << endl;
    }

    return 0;
}