#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string notes[] = {"Do", "Re", "Mi", "Fa", "So", "La", "Si"};
    string s;
    cin >> s;

    int cnt = 0;
    rep1(i, 14){
        if(s[i] == 'W') ++cnt;

        string subs = s.substr(i, 6);
        if(subs == "WBWBWB"){
            cout << cnt << endl;
            cout << notes[(10-cnt)%7] << endl;
            return 0;
        }
    }
}