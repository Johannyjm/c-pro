#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

bool is_ss(string s){
    if(s.length()%2) return false;

    bool flg;
    rep(i, s.length()/2){
        if(s[i]!=s[i+s.length()/2]) return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int res = s.length()-1;

    rep(i, s.length()){
        string tmp = s.substr(0, s.length()-(i+1));
        if(is_ss(tmp)) break;
        else --res;
    }

    cout << res << endl;

}