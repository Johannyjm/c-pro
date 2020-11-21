#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int n;
string s;
vector<bool> seen;

int dfs(int l, int r){

    int ret = 3;    
    if(l-1>=0 && r+2<n && s[l-1]=='f'&&s[r+1]=='o'&&s[r+2]=='x'){
        ret += dfs(l-1, r+2);
        seen[l-1] = true;
        seen[r+1] = true;
        seen[r+2] = true;
    }
    if(l-2>=0 && r+1<n && s[l-2]=='f'&&s[l-1]=='o'&&s[r+1]=='x'){
        ret += dfs(l-2, r+1);
        seen[l-2] = true;
        seen[l-1] = true;
        seen[r+1] = true;
    }

    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> s;

    seen.resize(n, false);
    int res = n;

    while(1){
        string sub = "";
        rep(i, n){
            if(!seen[i]) sub += s[i];
        }

        s = sub;
        bool flg = true;
        n = s.size();
        seen.clear();
        seen.resize(n, false);
        rep(i, n-2){
            if(s[i]=='f'&&s[i+1]=='o'&&s[i+2]=='x'){
                seen[i] = true;
                seen[i+1] = true;
                seen[i+2] = true;
                int cnt = dfs(i, i+2);
                res -= cnt;
                flg = false;
            }
        }

        if(flg) break;
    }

    cout << res << endl;

    return 0;
}