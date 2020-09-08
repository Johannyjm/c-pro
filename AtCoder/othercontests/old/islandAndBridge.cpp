#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    int total = 0;

    rep(i, n) {
        cin >> a[i];
        total += a[i];
    }

    if(total%n){
        cout << -1 << endl;
        return 0;
    }

    int target = total / n;
    int res = n;
    int ptr = 0;

    while(1){
        int subsum = 0;
        int cnt = 0;
        for(int j = ptr; j < n; ++j){
            subsum += a[j];
            ++cnt;
            if(subsum/cnt==target && subsum%cnt==0){
                --res;
                ptr = j+1;
                break;
            }
        }
        if(ptr >= n || cnt == n) break;
    }
    cout << res << endl;


}