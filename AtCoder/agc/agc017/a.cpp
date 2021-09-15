#include <iostream>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, p;
    cin >> n >> p;
    bool flg = true;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        if(a%2 == 1) flg = false;
    }
    if(flg && p == 1){
        cout << 0 << endl;
        return 0;
    }

    ll res = 1;
    for(int i = 0; i < n-1; ++i){
        res *= 2;
    }

    if(flg) res *= 2;

    cout << res << endl;

    return 0;
}
