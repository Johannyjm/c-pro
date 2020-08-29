#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int mx = 0;
    for(int i = 0; i < (n-m+1); ++i){
        int cnt = 0;
        for(int j = 0; j < m; ++j){
            if(s[i+j] == t[j])++cnt;
        }
        mx = max(mx, cnt);
    }

    cout << m-mx << endl;

    return 0;
}