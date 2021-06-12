#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b;
    cin >> a >> b;

    ll g = gcd(a, b);

    if(a > b) swap(a, b);
    b /= g;

    if(a * b < a || a*b > 1000000000000000000ll) cout << "Large" << endl;
    else cout << a * b << endl;

    return 0;
}
