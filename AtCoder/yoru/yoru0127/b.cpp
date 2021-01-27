#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    for(int i = 0; i < n; ++i) cin >> h[i];

    sort(h.begin(), h.end(), greater<int>());

    ll res = 0;
    for(int i = 0; i < n; ++i){
        if(i < k) continue;
        res += h[i];
    }

    cout << res << endl;

    return 0;
}
