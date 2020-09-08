#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    rep(i, h){
        rep(j, w){
            if(s[i][j] == '#') cout << '#';
            else{
                int cnt = 0;
                rep(dir, 8){
                    int di = i + dy[dir];
                    int dj = j + dx[dir];
                    if(di<0 || di>=h || dj<0 || dj>=w) continue;
                    
                    if(s[di][dj] == '#') ++cnt;
                }
                cout << cnt;
            }
        }
        cout << endl;
    }

    return 0;
}