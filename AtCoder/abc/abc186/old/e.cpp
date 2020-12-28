#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--){
        ll n, s, k;
        cin >> n >> s >> k;
        
        if((n-s)%k == 0){
            cout << (n-s) / k << endl;
            continue;
        }

        ll remain = ((n-s) + k - 1) / k;
        
        s += k * remain;

        ll remain2 = ((s-n) + n - 1) / n;

        n += n * remain2;
        

    }

    return 0;
}