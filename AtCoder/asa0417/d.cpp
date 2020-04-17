#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;

    vector<bool> seen(n, false);
    int right = 0;
    int left = 0;
    rep(i, n){
        if(s[i] == '('){
            bool found = false;
            for(int j = i+1; j < n; ++j){
                if(!seen[j] && s[j] == ')') {
                    found = true;
                    seen[j] = true;
                    break;
                }
            }
            if(!found) ++right;
        }

        else{
            bool found = false;
            for(int j = i-1; j >= 0; --j){
                if(!seen[j] && s[j] == '('){
                    found = true;
                    seen[j] = true;
                    break;
                }
            }
            if(!found) ++left;
        }
    }

    rep(_, left) cout << '(';
    cout << s;
    rep(_, right) cout << ')';
    cout << endl;

    return 0;
}