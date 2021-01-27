#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    ll sm = 0;
    ll evensm = 0;
    ll oddsm = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sm += a[i] * 2;
        if(i%2 == 0) oddsm += a[i] * 2;
        else evensm += a[i] * 2;
    }
    
    sm /= 2;

    vector<ll> res(n);
    for(int i = 0; i < n; ++i){
        if(i%2 == 0) res[i] = sm - ()ZZ
    }


    return 0;
}
