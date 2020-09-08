#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> button(9, 0);

    int res = 0;
    rep(i, n){
        string s;
        cin >> s;

        rep(j, s.size()){
            if(s[j]=='o') {
                button[j] = 1;
            }
            else{
                if(s[j]=='x') ++res;
                if(button[j]){
                    ++res;
                    button[j] = 0;
                }
            }
        }
    }
    rep(i, 9) res += button[i];

    cout << res << endl;

    return 0;
}