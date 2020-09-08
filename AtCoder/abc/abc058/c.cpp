#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> s(n);
    int min_len = 51;
    string str;
    rep(i, n) {
        cin >> str;
        s[i] = str;
        min_len = min(min_len, (int)str.size());
    }

    vector<string> res;
    bool flg = false;
    for(int i = min_len; i >= 1; --i) {
        rep(j, n){
            rep(k, s[j].size()-i+1){
                //cout << i << " " << j << " " << k << endl;
                //cout << s[j].substr(k, i) << endl;
                string substr = s[j].substr(k, i);

                rep(l, n){
                    if(l==j) continue;
                    rep(m, s[l].size()-i+1){
                        if(substr == s[l].substr(m, i)) {
                            res.push_back(substr);
                            flg = true;
                            break;
                        }
                    }
                    if(flg) break;
                }
                if(flg) break;
            }
            if(flg) break;
        }
        if(flg) break;
    }
    sort(res.begin(), res.end());
    cout << res[0] << endl;

    return 0;
}