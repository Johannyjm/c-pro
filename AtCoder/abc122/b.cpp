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

    int res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            string sub = s.substr(i, j-i+1);
            bool flg = true;
            rep(k, sub.size()){
                char c = sub[k];
                if(c=='A' || c=='C' || c=='G' || c=='T') flg = flg && true;
                else flg = false;
            }

            if(flg) res = max(res, (int)sub.size());
        }
    }

    cout << res << endl;


    return 0;
}