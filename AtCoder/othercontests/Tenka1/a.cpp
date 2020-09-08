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

    if(s.size() == 2) cout << s << endl;
    else{
        for(int i = s.size()-1; i >= 0; --i){
            cout << s[i];
        }
        cout << endl;
    }

    return 0;
}