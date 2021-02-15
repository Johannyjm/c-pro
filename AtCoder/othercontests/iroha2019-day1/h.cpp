#include <iostream>
using namespace std;
using ll = long long;

int f(ll n){
    int ret = 0;
    while(n){
        ret += n%10;
        n /= 10;
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    int d = f(n);

    string res = "";


    return 0;
}
