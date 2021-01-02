#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    rep1(i, n){
        if((n-i) % 2) continue;
        string sub = s.substr(0, n-i);
        int m = sub.size();

        bool is_ss = true;
        rep(j, m/2){
            if(sub[j] != sub[m/2 + j]) {
                is_ss = false;
                break;
            }
        }
        if(is_ss){
            cout << m << endl;
            return 0;
        }
    }

    return 0;
}