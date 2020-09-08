#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;

    vector<int> wtoe(n), etow(n);

    int echange = 0;
    wtoe[0] = 0;
    for(int i = 1; i < n; ++i){
        if(s[i-1]=='W') ++echange;
        wtoe[i] = echange;
    }

    int wchange = 0;
    etow[n-1] = 0;
    for(int i = n-2; i >= 0; --i){
        if(s[i+1] == 'E') ++wchange;
        etow[i] = wchange;
    }
    
    int res = 1e9;
    rep(i, n){
        res = min(res, wtoe[i] + etow[i]);
    }
    cout << res << endl;


}