#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    set<pair<int, int>> relations;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        relations.insert(make_pair(x, y));
    }

    int res = 0;
    rep1(i, 1<<n){
        int num = 0;
        vector<int> faction;
        rep(j, n){
            if(i & (1<<j)){
                faction.push_back(j);
                ++num;
            }
        }

        bool flg = true;
        for(int j = 0; j < num-1; ++j){
            for(int k = j+1; k < num; ++k){
                pair<int, int> relation = make_pair(faction[j], faction[k]);

                if(relations.find(relation) == relations.end()) {
                    flg = false;
                    break;
                }
            }
            if(!flg) break;
        }

        if(flg) res = max(res, num);

    }

    cout << res << endl;

    return 0;
}