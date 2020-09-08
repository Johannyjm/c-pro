#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> mn;
    int res = 0;
    int cap = 0;

    rep(i, n){
        int w;
        cin >> w;

        if(w > cap){
            ++res;
            cap = w;
            mn.push_back(w);
        }
        if(w < cap){
            rep(j, mn.size()){
                if(mn[j]<cap && mn[j]>=w) {
                    mn[j] = w;
                    break;
                }
                if(mn[j]==cap){
                    int topcnt = 0;
                    rep(k, mn.size()){
                        if(mn[k] == cap) ++topcnt;
                    }

                    if(topcnt == 1) cap = w;
                    mn[j] = w;

                    break;
                }
            }
        }
        // cout << cap << " ";
        // rep(j, mn.size()) cout << mn[j] << " ";

        // cout << endl;
    }

    cout << res << endl;

    return 0;
}