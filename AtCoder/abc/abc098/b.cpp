#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;

    int res = -1;
    
    rep(i, s.length()-1){
        string l = s.substr(0, i+1);
        string r = s.substr(i+1, s.length());

        int l_bucket[26] = {0};
        int r_bucket[26] = {0};

        rep(j, l.length()) ++l_bucket[l[j] - 'a'];
        rep(j, r.length()) ++r_bucket[r[j] - 'a'];
        
        int cnt = 0;
        rep(j, 26){
            if(l_bucket[j]>0 && r_bucket[j]>0) ++cnt;
        }
        res = max(res, cnt);
    }
    cout << res << endl;

}