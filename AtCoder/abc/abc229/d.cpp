#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    int k;
    cin >> s >> k;
    
    int n = s.size();

    if(n == 1){
        if(s == "." && k == 0) cout << 0 << endl;
        else cout << 1 << endl;
        return 0;
    }

    int res = 0;
    int r = 0;
    int nowdot = 0;
    int nowx = 0;
    if(s[0] == '.') ++nowdot;
    else ++nowx;

    for(int l = 0; l < n; ++l){
        if(l > 0){
            if(s[l-1] == '.') --nowdot;
            else --nowx;
        }

        // if(r < l) r = l;

        while(nowdot <= k){
            ++r;
            if(r >= n) break;
            
            if(s[r] == '.') ++nowdot;
            else ++nowx;

            if(nowdot > k) break;
            
            res = max(res, nowx+nowdot);
            // cout << l << " " << r << " " << nowdot << " " << nowx << endl;
        }
    }

    cout << res << endl;

    return 0;
}
