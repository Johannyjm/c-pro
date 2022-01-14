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

    unordered_map<int, int> cnt;

    int res = 0;
    int r = 0;
    int now = 0;
    while(1){
        
        if(cnt[a[r]] == 0 && now == k)
            break;

        ++cnt[a[r]];
        
        if(cnt[a[r]] == 1)
            ++now;
        
        ++r;

        if(r == n)
            break;
    }

    
    for(int l = 0; l < n; ++l){

        if(l > 0){
            --cnt[a[l-1]];
            if(cnt[a[l-1]] == 0) --now;
        }
        
        while(now <= k){
            ++r;
            ++cnt[a[r]];
            if(cnt[a[r]] == 1) ++now;
        }

        res = max(res, r-l+1);
    }

    cout << res << endl;

    return 0;
}
