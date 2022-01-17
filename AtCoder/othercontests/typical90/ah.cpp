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
    int now = 1;
    cnt[a[0]] = 1;
    int r = 0;

    int res = 0;

    for(int l = 0; l < n; ++l){
        
        if(l > 0){
            --cnt[a[l]];
            if(cnt[a[l]] == 0) --now;
        }

        if(now > k) continue;
        
        bool isedge = false;
        while(now <= k){
            ++r;
            if(r == n){
                break;
                isedge = true;
            }
            
            ++cnt[a[r]];
            if(cnt[a[r]] == 1) ++now;
        }
        
        if(!isedge){
            --now;
            --cnt[a[r]];
            --r;
        }

        res = max(res, r-l+1);
    }

    cout << res << endl;
    

    return 0;
}
