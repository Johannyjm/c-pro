#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    char s[h][w];
    rep(i, h) rep(j, w) cin >> s[i][j];

    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '#') cout << '#';
            else {
                int cnt = 0;

                if(j+1<w && s[i][j+1]=='#')++cnt;
                if(i+1<h && j+1<w && s[i+1][j+1]=='#')++cnt;
                if(i+1<h && s[i+1][j]=='#')++cnt;
                if(i+1<h && j-1>=0 && s[i+1][j-1]=='#')++cnt;
                if(j-1>=0 && s[i][j-1]=='#')++cnt;
                if(i-1>=0 && j-1>=0 && s[i-1][j-1]=='#')++cnt;
                if(i-1>=0 && s[i-1][j]=='#')++cnt;
                if(i-1>=0 && j+1<w && s[i-1][j+1]=='#')++cnt;

                cout << cnt;
            }
        }
        cout << endl;
    }
}