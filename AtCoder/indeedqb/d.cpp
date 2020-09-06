#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, c;
    cin >> n >> c;

    vector<ll> a(n);
    vector<vector<int>> idx(c);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        --a[i];
        idx[a[i]].push_back(i);
    }

    for(int i = 0; i < c; ++i){
        ll res = 0;
        int ptr = 0;
        for(int j = 0; j < idx[i].size(); ++j){
            res += (idx[i][j]-ptr+1) * (n-idx[i][j]);
            ptr = idx[i][j] + 1;
        }
        cout << res << "\n";
    }

    return 0;
}
