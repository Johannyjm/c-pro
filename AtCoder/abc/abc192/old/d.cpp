#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

ll basen(string x, int d){
    ll ret = 0;
    ll base = 1;
    int n = x.size();

    for(int i = n-1; i >= 0; --i){
        ret += (x[i]-'0') * base;
        base *= d;
        if(base < 0) return -1;
    }

    return ret;
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string x;
    ll m;
    cin >> x >> m;

    int d = 0;
    for(auto c: x){
        d = max(d, c-'0');
    }

    int res = 0;
    for(int i = d+1;; ++i){
        // cout << i << " " << basen(x, i) << endl;
        ll b = basen(x, i);
        if(b!=-1 && b<=m) ++res;
        else break;
    }

    cout << res << endl;

    return 0;
}
