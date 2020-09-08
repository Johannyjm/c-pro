#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; ++i) cin >> s[i];
    sort(s.begin(), s.end());

    int q;
    cin >> q;
    vector<int> res(q);
    map<int, int> dp;

    auto passnum = [&](int border){
        if(dp[border] > 0) return dp[border];
        int idx = lower_bound(s.begin(), s.end(), border) - s.begin();
        return dp[border] = n - idx;
    };

    for(int i = 0; i < q; ++i){
        int k;
        cin >> k;
        
        int ok = s.back()+1;
        int ng = 0;

        if(passnum(1) <= k){
            res[i] = 0;
            continue;
        }
        while(ok - ng > 1){
            int mid = (ok + ng) / 2;
            
            if(passnum(mid) > k) ng = mid;
            else ok = mid;
        }

        res[i] = ok;
        
    }

    for(int i = 0; i < q; ++i) cout << res[i] << endl;
}
