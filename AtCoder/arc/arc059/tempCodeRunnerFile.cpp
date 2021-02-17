#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    if(n == 2){
        if(s[0] == s[1]) cout << "1 2" << endl;
        else cout << "-1 -1" << endl;
        return 0;
    }

    rep(i, n-2){
        if(s[i]==s[i+1] || s[i]==s[i+2]){
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }

    cout << "-1 -1" << endl;

    return 0;
}