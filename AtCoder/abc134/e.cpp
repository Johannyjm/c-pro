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

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    map<int, int> nouse;
    int l = n;
    int res = 0;

    while(l > 0){
        ++res;

        vector<int> dp;
        int ptr = 0;
        while(nouse[ptr]>0) ++ptr;
        dp.push_back(a[ptr]);
        vector<int> lis;
        lis.push_back(-1);
        int st = 0;
        rep(i, n){
            if(nouse[i] > 0) continue;
            if(a[i] > dp.back()) {
                dp.push_back(a[i]);
                lis.push_back(a[i]);
                ++nouse[i];
                if(lis.size() == 2) st = i;
            }
            else{
                int idx = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
                dp[idx] = a[i];
            }
        }

        if(dp.size() > 1){
            int no = -1;
            rep(i, st){
                if(a[i] < lis[1]) {
                    if(a[i] > lis[0]){
                        lis[0] = a[i];
                        no = i;
                    }
                }
            }
            ++nouse[no];
        }

        l -= dp.size();
    }

    cout << res << endl;
    

    return 0;
}