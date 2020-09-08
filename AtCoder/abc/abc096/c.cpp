#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    char s[h][w];
    rep(i, h) rep(j, w) cin >> s[i][j];

    rep(i, h){
        rep(j, w){
            if(s[i][j] == '#'){
                bool up = false;
                bool down = false;
                bool left = false;
                bool right = false;

                if(i>=1){
                    if(s[i-1][j] == '.') up = true;
                }
                else up = true;

                if(i<=h-2){
                    if(s[i+1][j] == '.') down = true;
                }
                else down = true;

                if(j>=1){
                    if(s[i][j-1] == '.') left = true;
                }
                else left = true;

                if(j<=w-2){
                    if(s[i][j+1] == '.') right = true;
                }
                else right = true;

                if(up && down && left && right){
                    puts("No");
                    return 0;
                }
            }
        }
    }

    puts("Yes");
    return 0;
}