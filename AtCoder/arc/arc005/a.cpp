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

    int res = 0;
    rep(_, n){
        string s;
        cin >> s;

        if(s=="TAKAHASHIKUN" || s=="Takahashikun" || s=="takahashikun") ++res;
        if(s=="TAKAHASHIKUN." || s=="Takahashikun." || s=="takahashikun.") ++res;
    }

    cout << res << endl;

    return 0;
}