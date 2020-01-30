#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    int ta = a;
    int tb = b;
    int tc = c;

    int res = 0;
    while(1){
        if(ta%2 || tb%2 || tc%2) break;
        int tea = ta/2;
        int teb = tb/2;
        int tec = tc/2;

        ta = teb + tec;
        tb = tec + tea;
        tc = tea + teb;
        
        if(ta == a && tb ==b && tc == c){
            cout << -1 << endl;
            return 0;
        }
        ++res;
    }

    cout << res << endl;

    return 0;
}