#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> ltor(n+1, 0);
    vector<int> rtol(n+1, 0);

    int cnt = 0;
    rep(i, n-1){
        if(s[i] == '<' && s[i+1] == '>') {
            ltor[i] += cnt + 1;
            cnt = 0;
        }
        else if(s[i] == '<') ++cnt;
    }
    if(s[n-1] == '<') ltor[n] = cnt + 1;

    cnt = 0;
    for(int i = n-1; i >= 1; --i){
        if(s[i] == '>' && s[i-1] == '<'){
            rtol[i-1] += cnt + 1;
            cnt = 0;
        }
        else if(s[i] == '>') ++cnt;
    }
    if(s[0] == '>') rtol[0] = cnt + 1;

    rep(i, n+1) cout << ltor[i] << " ";
    cout << endl;
    rep(i, n+1) cout << rtol[i] << " ";
    cout << endl;

    vector<int> res(n+1, 0);
    if(s[0]=='<') res[0] = 0;
    else res[0] = max(ltor[0], rtol[0]);
    
    rep(i, n-1){
        if(s[i] == '<' && s[i+1] == '<') {
            res[i+1] = res[i] + 1;
        }
        if(s[i] == '>' && s[i+1] == '>') {
            res[i+1] = res[i] - 1;
        }
        if(s[i] == '>' && s[i+1] == '<') {
            res[i+1] = 0;
        }
        if(s[i] == '<' && s[i+1] == '>') {
            res[i+1] = max(ltor[i], rtol[i]);
        }
    }
    cout << endl;
    rep(i, n+1) cout << res[i] << " ";
    cout << endl;

    if(s[n-1] == '>') res[n] = 0;
    else res[n] = max(ltor[n], rtol[n]);

    for(int i = n-1; i >= 1; --i){
        if(s[i] == '>' && s[i-1] == '>'){
            res[i] = min(res[i+1] + 1, res[i]);
        }
    }

    cout << endl;
    rep(i, n+1) cout << res[i] << " ";
    cout << endl << endl;

    int ans = 0;
    rep(i, n+1) ans += res[i];

    cout << ans << endl;

    return 0;
}