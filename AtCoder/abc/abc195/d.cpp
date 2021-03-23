#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> w(n), v(n);
    vector<pair<int, int>> vw(n);
    for(int i = 0; i < n; ++i){
        cin >> w[i] >> v[i];
        vw[i] = {v[i], w[i]};
    }
    
    sort(vw.begin(), vw.end(), greater<pair<int, int>>());

    vector<int> x(m);
    for(int i = 0; i < m; ++i) cin >> x[i];

    for(int _ = 0; _ < q; ++_){
        int l, r;
        cin >> l >> r;
        --l;
        --r;

        vector<int> use;
        for(int i = 0; i < m; ++i){
            if(l <= i && i <= r) continue;
            use.push_back(x[i]);
        }

        sort(use.begin(), use.end());
        vector<bool> seen((int)use.size());
        
        int res = 0;
        for(auto p: vw){
            for(int i = 0; i < (int)use.size(); ++i){
                if(seen[i]) continue;
                if(use[i] >= p.second){
                    seen[i] = true;
                    res += p.first;
                    break;
                }
            }
        }

        cout << res << endl;

    }

    return 0;
}
