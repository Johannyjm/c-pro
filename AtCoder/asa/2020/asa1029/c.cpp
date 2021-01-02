#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> east(n+1, 0), west(n+1, 0);
    rep(i, n){
        if(s[i] == 'E') ++east[i+1];
        else ++west[i+1];

        east[i+1] += east[i];
        west[i+1] += west[i];
    }

    // rep(i, n+1) cout << east[i] << " ";
    // cout << endl;
    // rep(i, n+1) cout << west[i] << " ";
    // cout << endl;

    int res = 1001001001;
    rep(i, n){
        int sm = west[i] + (east[n] - east[i+1]);
        res = min(res, sm);
    }

    cout << res << endl;

    return 0;
}