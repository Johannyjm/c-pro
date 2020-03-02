#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    string res = "0";
    if(n == 2) res = "10";
    if(n == 3) res = "100";
    bool isfix[3] = {false, false, false};

    rep(i, m){
        int s;
        char c;
        cin >> s >> c;
        --s;
        if((n!=1 && s==0 && c=='0') || (isfix[s] && res[s] != c)){
            cout << -1 << endl;
            return 0;
        }

        res[s] = c;
        isfix[s] = true;
    }

    cout << res << endl;

    return 0;
}