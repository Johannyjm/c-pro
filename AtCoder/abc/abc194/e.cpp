#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    unordered_map<int, int> mp;
    for(int i = 0; i < n; ++i) cin >> a[i];

    for(int i = 0; i < m; ++i) ++mp[a[i]];

    int now = 0;
    while(mp[now] != 0) ++now;
    

    int res = now;
    for(int i = 1; i < n-m+1; ++i){
        int drop = a[i-1];
        int add = a[i+m-1];
        
        if(drop == add) continue;

        --mp[drop];
        if(mp[drop] == 0){
            if(drop < now){
                now = drop;
            }
        }

        ++mp[add];
        if(mp[add] == 1){
            if(add == now){
                while(mp[now] != 0) ++now;
            }
        }

        res = min(res, now);
    }

    cout << res << endl;

    return 0;
}
