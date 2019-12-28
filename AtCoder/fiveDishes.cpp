#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int dishes[5];
    int min_one = 10;
    int last_idx = 0;
    rep(i, 5) {
        int dish;
        cin >> dish;
        if(dish%10 && dish%10 < min_one) {
            min_one = dish%10;
            last_idx = i;
        }

        dishes[i] = dish;
    }

    int res = 0;
    rep(i, 5){
        if(i != last_idx) res += 10*(dishes[i]/10 + 1*(dishes[i]%10!=0));
    }
    res += dishes[last_idx];
    
    cout << res << endl;
}