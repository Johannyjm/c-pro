#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    int q;
    cin >> q;
    for(int i = 0; i < q; ++i){
        int b;
        cin >> b;
        int idx1 = lower_bound(a.begin(), a.end(), b) - a.begin();
        int idx2 = upper_bound(a.begin(), a.end(), b) - a.begin();
        
        int res = 1001001001;
        for(int j = -1; j <= 1; ++j){
            int idx3 = min(max(idx1+j, 0), n-1);
            int idx4 = min(max(idx2+j, 0), n-1);
            res = min(res, abs(a[idx3] - b));
            res = min(res, abs(a[idx4] - b));
        }

        cout << res << "\n";
    }

    return 0;
}
