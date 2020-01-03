#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

bool is_ex(int x){
    if(x == 1) return true;
    for (int i = 2; i < x; ++i){
        for(int j = 1; j < x; ++j){
            int tmp = i;
            for(int k = 0; k < j; ++k) tmp *= i;
            if(tmp == x) return true;
            if(tmp > x) break;
        }
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x;
    cin >> x;

    int res;
    for(int i = 1; i <= x; ++i){
        if(is_ex(i))res = i;
    }
    cout << res << endl;
}