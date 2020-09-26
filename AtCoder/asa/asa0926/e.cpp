#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(k));
    rep(i, n) rep(j, k) cin >> a[i][j];

    vector<vector<int>> fixed(n, vector<int>(k, -1));
    unordered_set<int> used, printed;
    vector<int> res;

    rep(i, n){
        rep(j, k){
            fixed[i][j] = a[i][j];
        }

        res.clear();
        used.clear();
        int cnt = 0;
        bool flg = false;
        rep(jj, k){
            rep(ii, n){
                if(fixed[ii][jj] != -1){
                    // cout << i << " " << cnt << " " << fixed[ii][jj] << " " << (used.find(fixed[ii][jj]) == used.end()) << endl;
                    if(used.find(fixed[ii][jj]) == used.end()){
                        ++cnt;
                        used.insert(fixed[ii][jj]);
                        if(printed.find(fixed[ii][jj]) == used.end())res.push_back(fixed[ii][jj]);
                        printed.insert(fixed[ii][jj]);
                        if(cnt == k){
                            flg = true;
                            break;
                        }
                    }
                }
                else{
                    ++cnt;
                    if(cnt == k){
                        flg = true;
                        break;
                    }
                }
            }
            if(flg) break;
        }

        sort(res.begin(), res.end());

        for(int elem: res) cout << elem << " ";
        cout << endl;
    }

    return 0;
}