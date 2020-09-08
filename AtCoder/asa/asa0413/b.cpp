#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    rep(i, h) cin >> s[i];

    bool flg = true;
    rep(i, h){
        rep(j, w){
            if(s[i][j] == '#'){
                bool all_white = true;
                rep(dir, 4){
                    int ni = i + dy[dir];
                    int nj = j + dx[dir];

                    if(ni<0 || ni>=h || nj<0|| nj>=w) continue;

                    if(s[ni][nj] == '#'){
                        all_white = false;
                        break;
                    }
                }

                if(all_white){
                    puts("No");
                    return 0;
                }
            }
        }
    }

    puts("Yes");

    return 0;
}