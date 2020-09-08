#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll k;
    cin >> k;

    int res = 1;
    int now = 7;
    for(int i = 0; i < k; ++i){
        if(now % k == 0){
            cout << res << endl;
            return 0;
        }
        now %= k;
        now = now * 10 + 7;
        ++res;
    }

    cout << -1 << endl;
}
