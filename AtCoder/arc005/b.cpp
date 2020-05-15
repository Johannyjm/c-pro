#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x, y;
    string w;
    cin >> x >> y >> w;
    --x;
    --y;

    vector<string> c(9);
    rep(i, 9) cin >> c[i];

    pair<int, int> dir; // pair[y, x]
    if(w == "R") dir = make_pair(0, 1);
    if(w == "L") dir = make_pair(0, -1);
    if(w == "U") dir = make_pair(-1, 0);
    if(w == "D") dir = make_pair(1, 0);
    if(w == "RU") dir = make_pair(-1, 1);
    if(w == "RD") dir = make_pair(1, 1);
    if(w == "LU") dir = make_pair(-1, -1);
    if(w == "LD") dir = make_pair(1, -1);

    string res = "";
    res += c[y][x];

    int i = y;
    int j = x;
    while(res.size() != 4){
        int ni = i + dir.first;
        int nj = j + dir.second;

        if(!(ni<0 || ni>=9 || nj<0|| nj>=9)) res += c[ni][nj];
        else{
            if(ni < 0) dir.first = 1;
            if(ni >= 9) dir.first = -1;
            if(nj < 0) dir.second = 1;
            if(nj >= 9) dir.second = -1;
            
            continue;
        }

        i = ni;
        j = nj;
    }
    
    cout << res << endl;

    return 0;
}