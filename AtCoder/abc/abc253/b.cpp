#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<int> x, y;
    rep(i, h) rep(j, w){
        if(s[i][j] == 'o'){
            y.push_back(i);
            x.push_back(j);
        }
    }

    cout << abs(y[0] - y[1]) + abs(x[0] - x[1]) << endl;

    return 0;
}