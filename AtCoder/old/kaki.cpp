#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n = 12;
    int res = 0;
    rep(i, n){
        string s;
        cin >> s;

        for(int j = 0; j < s.length(); ++j){
            if(s[j]=='r'){
                ++res;
                break;
            }
        }
    }
    cout << res << endl;
}