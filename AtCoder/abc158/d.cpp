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
    int q;
    cin >> q;
    int rev = 0;
    
    string res = s;

    rep(i, q){
        int t;
        cin >> t;

        if(t==1) rev = 1 - rev;
        else{
            int f;
            char c;
            cin >> f >> c;
            if((f==1 && rev==0) || (f==2 && rev==1)) res = c + res;
            if((f==2 && rev==0) || (f==1 && rev==1)) res = res + c;
        }
    }

    if(rev){
        reverse(res.begin(), res.end());
        cout << res << endl;
    }

    else cout << res << endl;

    return 0;
}