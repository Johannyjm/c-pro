#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    string s;
    cin >> n >> q >> s;

    rep(i, q){
        int l, r;
        cin >> l >> r;

        --l;
        string sub = s.substr(l, r-l);
        
        int cnt = 0;
        rep(j, sub.size()-1){
            if(sub[j] == 'A' && sub[j+1] == 'C'){
                ++cnt;
            }
        }
        cout << cnt << endl;
    }


    return 0;
}