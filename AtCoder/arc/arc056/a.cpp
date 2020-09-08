#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, k, l, res;
    cin >> a >> b >> k >> l;

    if(a*l == b) res = a * k;
    else{
        int break_even;
        rep1(i, l+1){
            if(a*i > b){
                break_even = i;
                break;
            }
        }

        if(k%l){
            if(k%l < break_even) res = b*(k/l) + a*(k%l);
            else res = b*(k/l + 1);
        }
        else res = b*k/l;
        
    }

    cout << res << endl;

    return 0;
}