#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    string tmp_t = t;

    rep(i, s.length()){
        if(s == tmp_t){
            puts("Yes");
            return 0;
        }
        tmp_t = tmp_t[tmp_t.length()-1] + tmp_t.substr(0, tmp_t.length()-1);
    }
    
    puts("No");
    return 0;
}