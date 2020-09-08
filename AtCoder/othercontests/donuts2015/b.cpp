#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<int> b(m), c(m);
    vector<vector<int>> d(m);
    for(int i = 0; i < m; ++i){
        cin >> b[i] >> c[i];
        vector<int> dd(c[i]);
        for(int j = 0; j < c[i]; ++j){
            cin >> dd[j];
            --dd[j];
        }
        d[i] = dd;
    }
    
    int res = 0;
    for(int i = 0; i < (1<<n); ++i){
        vector<int> use(n, 0);
        int cnt = 0;
        for(int j = 0; j < n; ++j){
            if(i & (1<<j)){
                use[j] = 1;
                ++cnt;
            }
        }
        if(cnt != 9) continue;
        int sm = 0;
        for(int j = 0; j < n; ++j){
            sm += use[j] * a[j];
        }

        for(int com = 0; com < m; ++com){
            int combo_cnt = 0;
            for(int idx = 0; idx < c[com]; ++idx){
                if(use[d[com][idx]] == 1) ++combo_cnt;
            }

            if(combo_cnt >= 3) sm += b[com];
        }

        res = max(res, sm);
    }

    cout << res << endl;

    return 0;
}
