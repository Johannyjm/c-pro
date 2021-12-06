#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<int> prv(n, -1), nxt(n, -1);
    while(q--){
        int cmd;
        cin >> cmd;
        if(cmd == 1){
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            prv[y] = x;
            nxt[x] = y;
        }
        if(cmd == 2){
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            prv[y] = -1;
            nxt[x] = -1;
        }
        if(cmd == 3){
            int x;
            cin >> x;
            --x;
            while(prv[x] != -1){
                x = prv[x];
            }
            vector<int> res;
            res.push_back(x);
            while(nxt[x] != -1){
                res.push_back(nxt[x]);
                x = nxt[x];
            }

            cout << res.size() << " ";
            for(auto e: res) cout << e+1 << " ";
            cout << endl;
        }
    }

    return 0;
}