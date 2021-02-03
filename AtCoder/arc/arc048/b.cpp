#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> r(n), h(n);
    vector<vector<int>> rbucket(110000);
    vector<unordered_map<int, int>> rhands(110000);
    rep(i, n){
        cin >> r[i] >> h[i];
        rbucket[r[i]].push_back(i);
        ++rhands[r[i]][h[i]];
    }

    vector<int> won(110000, 0), lost(110000, 0);
    rep(i, 101000) won[i+1] = won[i] + (int)rbucket[i].size();
    for(int i = 101000; i > 0; --i) lost[i-1] = lost[i] + (int)rbucket[i].size();

    rep(i, n){
        int res1 = won[r[i]];
        int res2 = lost[r[i]];
        int res3 = 0;
        if(h[i]==1){
            res1 += rhands[r[i]][2];
            res2 += rhands[r[i]][3];
            res3 += rhands[r[i]][1] - 1;
        }
        if(h[i]==2){
            res1 += rhands[r[i]][3];
            res2 += rhands[r[i]][1];
            res3 += rhands[r[i]][2] - 1;
        }
        if(h[i]==3){
            res1 += rhands[r[i]][1];
            res2 += rhands[r[i]][2];
            res3 += rhands[r[i]][3] - 1;
        }
        
        cout << res1 << " " << res2 << " " << res3 << endl;
    }

    return 0;
}