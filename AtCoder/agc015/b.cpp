#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    ll res = n * (n - 1);

    rep(i, n){
        if(s[i] == 'U'){
            res += i;
        }

        else{
            res += n - i - 1;
        }
    }

    cout << res << endl;

    return 0;
}