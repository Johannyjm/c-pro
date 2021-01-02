#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
 
    string s;
    cin >> s;
    int n = s.size();
 
    int end = n;
    for(int i = n-1; i >= 0; --i){
        if(s[i] == 'B') --end;
        if(s[i] == 'W') break;
    }
    n = end;
 
    ll res = 0;
    rep(i, n){
        if(s[i] == 'B') {
            res += end - i - 1;
            --end;
        }
    }
 
    cout << res << endl;
 
    return 0;
}