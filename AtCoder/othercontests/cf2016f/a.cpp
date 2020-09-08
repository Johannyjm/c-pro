#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    rep(i, h){
        rep(j, w){
            string s;
            cin >> s;

            if(s=="snuke"){
                char res = 'A' + j;
                cout << res << i+1 << endl;
                return 0;
            }
        }
    }

    return 0;
}