#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    map<char, int> mp;
    mp['b'] = '1';
    mp['c'] = '1';
    mp['d'] = '2';
    mp['w'] = '2';
    mp['t'] = '3';
    mp['j'] = '3';
    mp['f'] = '4';
    mp['q'] = '4';
    mp['l'] = '5';
    mp['v'] = '5';
    mp['s'] = '6';
    mp['x'] = '6';
    mp['p'] = '7';
    mp['m'] = '7';
    mp['h'] = '8';
    mp['k'] = '8';
    mp['n'] = '9';
    mp['g'] = '9';
    mp['z'] = '0';
    mp['r'] = '0';
    
    string res = "";
    rep(i, n){
        string w;
        cin >> w;
        string ans = "";
        rep(j, w.size()){
            if(('a' <= w[j] && w[j] <= 'z') || ('A' <= w[j] && w[j] <= 'Z')){
                if(w[j]!='a' || w[j]!='e' || w[j]!='i' || w[j]!='o' || w[j]!='u' || w[j]!='y' || w[j]!='A' || w[j]!='E' || w[j]!='I' || w[j]!='O' || w[j]!='U' || w[j]!='Y'){
                    if('a' <= w[j] && w[j] <= 'z') ans += mp[w[j]];
                    else ans += mp['a' + w[j] - 'A'];
                }
            }
        }
        if(ans.size() > 1){
            res += ans;
            res += " ";
        }
    }

    if(res != "") res.pop_back();
    cout << res << endl;

    return 0;
}