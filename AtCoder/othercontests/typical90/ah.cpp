#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    int res = 0;
    int now = 1;
    int r = 1;
    unordered_map<int, int> cnt;
    ++cnt[a[0]];
    for(int l = 0; l < n; ++l){
        if(l > 0){
            --cnt[a[l-1]];
            if(cnt[a[l-1]] == 0) --now;
        }
        while(1){
            if(r < n && now < k){
                ++cnt[a[r]];
                if(cnt[a[r]] == 1) ++now;
            }
            else break;
            ++r;
        }
        cout << l << " " << r << endl;
        res = max(res, r-l);
    }

    cout << res << endl;

    return 0;
}
