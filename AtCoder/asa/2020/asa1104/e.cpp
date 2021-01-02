#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> l(n);
    rep(i, n) cin >> l[i];
    
    int res = 1001001001;
    rep(i, pow(4, n)){
        vector<int> fusion(n, 0);
        int ti = i;
        int ptr = 0;
        while(ti){
            fusion[ptr] = ti%4;
            ti /= 4;
            ++ptr;
        }
        // rep(j, n) cout << fusion[j] << " ";
        // cout << endl;
        vector<int> after;
        
        for(int idx = 1; idx <= 3; ++idx){
            int fusionx = 0;
            rep(j, n){
                if(fusion[j] == idx) fusionx += l[j];
            }
            if(fusionx != 0) after.push_back(fusionx);
        }

        rep(j, n){
            if(fusion[j] == 0) after.push_back(l[j]);
        }

        int m = after.size();
        int sm = (n-m)*10;
        int used_a = -1;
        int used_b = -1;
        
        // for A
        int mn = 1001001001;
        rep(j, m){
            if(abs(after[j]-c) < mn){
                mn = abs(after[j]-c);
                used_a = j;
            }
        }
        sm += mn;

        // for B
        mn = 1001001001;
        rep(j, m){
            if(j == used_a) continue;
            if(abs(after[j]-b) < mn){
                mn = abs(after[j]-b);
                used_b = j;
            }
        }
        sm += mn;

        // for C
        mn = 1001001001;
        rep(j, m){
            if(j==used_a || j==used_b) continue;
            mn = min(mn, abs(after[j]-a));
        }
        sm += mn;

       
        res = min(res, sm);
    }

    cout << res << endl;

    return 0;
}