#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    map <string, int> mp;
    int max_vote = 0;
    string res;

    rep(i, n){
        string s;
        cin >> s;
        ++mp[s];
        if(max_vote<mp[s]){
            max_vote = mp[s];
            res = s;
        }
    }
    
    cout << res << endl;

}