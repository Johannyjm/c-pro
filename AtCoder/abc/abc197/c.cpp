#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    ll res = 1ll << 60;
    for(int i = 0; i < (1<<(n-1)); ++i){
        vector<int> sep(n-1, 0);
        for(int j = 0; j < n-1; ++j){
            if(i & (1<<j)) sep[j] = 1;
        }

        vector<int> ors;
        int now = a[0];
        for(int j = 1; j < n; ++j){
            if(sep[j-1] == 1){
                now |= a[j];
            }
            else{
                ors.push_back(now);
                now = a[j];
            }
        }
        ors.push_back(now);

        ll val = 0;
        for(auto e: ors) val ^= e;

        res = min(res, val);
    }


    cout << res << endl;


    return 0;
}
