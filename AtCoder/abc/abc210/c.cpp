#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for(int i = 0; i < n; ++i) cin >> c[i];

    unordered_map<int, int> mp;
    int res = 0;
    int cnt = 0;
    for(int i = 0; i < k; ++i){
        ++mp[c[i]];
        if(mp[c[i]] == 1){
            ++cnt;
        }
        res = max(res, cnt);
    }

    for(int i = k; i < n; ++i){
        int r = i;
        int l = r-k;

        --mp[c[l]];
        if(mp[c[l]] == 0){
            --cnt;
        }
        
        ++mp[c[r]];
        if(mp[c[r]] == 1){
            ++cnt;
        }

        res = max(res, cnt);
    }

    cout << res << endl;

    return 0;
}
