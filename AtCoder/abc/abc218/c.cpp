#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> s(n), t(n);
    rep(i, n) cin >> s[i];
    rep(i, n) cin >> t[i];

    if(n==1){
        if(s == t) puts("Yes");
        else puts("No");
        return 0;
    }

    // orignal shape
    int sy = -1;
    int sx = -1;
    bool found = false;
    rep(i, n){
        rep(j, n){
            if(s[i][j] == '#'){
                sy = i;
                sx = j;
                found = true;
                break;
            }
        }
        if(found) break;
    }

    vector<pair<int, int>> shapes;
    rep(i, n) rep(j, n){
        if(i==sy && j==sx) continue;
        if(s[i][j] != '#') continue;
        shapes.push_back({i-sy, j-sx});
    }

    // for(auto e: shapes) cout << e.first << " " << e.second << endl;

    // checking shape 1
    int ty = -1;
    int tx = -1;
    found = false;
    rep(i, n){
        rep(j, n){
            if(t[i][j] == '#'){
                ty = i;
                tx = j;
                found = true;
                break;
            }
        }
        if(found) break;
    }
    vector<pair<int, int>> tshapes;
    rep(i, n) rep(j, n){
        if(i==ty && j==tx) continue;
        if(t[i][j] != '#') continue;
        tshapes.push_back({i-ty, j-tx});
    }

    if(shapes == tshapes){
        puts("Yes");
        return 0;
    }

    // checking shape 2
    ty = -1;
    tx = -1;
    found = false;
    rep(j, n){
        for(int i = n-1; i >= 0; --i){
            if(t[i][j] == '#'){
                ty = i;
                tx = j;
                found = true;
                break;
            }
        }
        if(found) break;
    }
    vector<pair<int, int>> tshapes2;
    rep(j, n) for(int i = n-1; i >= 0; --i){
        if(i==ty && j==tx) continue;
        if(t[i][j] != '#') continue;
        tshapes2.push_back({j-tx, -(i-ty)});
    }

    if(shapes == tshapes2){
        puts("Yes");
        return 0;
    }

    // checking shape 3
    ty = -1;
    tx = -1;
    found = false;
    for(int i = n-1; i >= 0; --i){
        for(int j = n-1; j >= 0; --j){
            if(t[i][j] == '#'){
                ty = i;
                tx = j;
                found = true;
                break;
            }
        }
        if(found) break;
    }
    vector<pair<int, int>> tshapes3;
    for(int i = n-1; i >= 0; --i) for(int j = n-1; j >= 0; --j){
        if(i==ty && j==tx) continue;
        if(t[i][j] != '#') continue;
        tshapes3.push_back({-(i-ty), -(j-tx)});
    }

    if(shapes == tshapes3){
        puts("Yes");
        return 0;
    }

    // checking shape 4
    ty = -1;
    tx = -1;
    found = false;
    for(int j = n-1; j >= 0; --j){
        rep(i, n){
            if(t[i][j] == '#'){
                ty = i;
                tx = j;
                found = true;
                break;
            }
        }
        if(found) break;
    }
    vector<pair<int, int>> tshapes4;
    for(int j = n-1; j >= 0; --j) rep(i, n){
        if(i==ty && j==tx) continue;
        if(t[i][j] != '#') continue;
        tshapes4.push_back({-(j-tx), i-ty});
    }

    if(shapes == tshapes4){
        puts("Yes");
        return 0;
    }

    // for(auto e: shapes) cout << e.first << " " << e.second << endl;
    // cout << endl;
    // for(auto e: tshapes) cout << e.first << " " << e.second << endl;
    // cout << endl;
    // for(auto e: tshapes2) cout << e.first << " " << e.second << endl;
    // cout << endl;
    // for(auto e: tshapes3) cout << e.first << " " << e.second << endl;
    // cout << endl;
    // for(auto e: tshapes4) cout << e.first << " " << e.second << endl;

    puts("No");

    return 0;
}