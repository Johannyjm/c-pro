#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    
    int res = 0;
    unordered_map<int, int> mp;
    for(int e: a){
        mp[e] = mp[e-k] + 1;
        res = max(res, mp[e]);
    }

    if(res > 1) cout << res << endl;
    else cout << -1 << endl;

    return 0;
}
