#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int k;
    string a, b;
    cin >> k >> a >> b;

    int base = 1;
    ll a10 = 0;
    reverse(a.begin(), a.end());
    for(auto c: a){
        int d = c - '0';
        a10 += base * d;
        base *= k;
    }

    base = 1;
    ll b10 = 0;
    reverse(b.begin(), b.end());
    for(auto c: b){
        int d = c - '0';
        b10 += base * d;
        base *= k;
    }

    cout << a10 * b10 << endl;

    return 0;
}