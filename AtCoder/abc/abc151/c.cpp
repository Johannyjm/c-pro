#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> p(m);
    vector<string> s(m);
    rep(i, m) cin >> p[i] >> s[i];
    int res1 = 0;
    int res2 = 0;
    vector<bool> seen(110000, false);
    vector<int> pena(110000, 0);
    rep(i, m){
        if(s[i] == "AC"){
            if(!seen[p[i]]){
                ++res1;
                seen[p[i]] = true;
                res2 += pena[p[i]];
            }
        }
        if(s[i] == "WA"){
            ++pena[p[i]];
        }
    }

    cout << res1 << " " << res2 << endl;

    return 0;
}