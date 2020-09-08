#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll a, b, c;
    cin >> a >> b >> c;

    if(a%2==0 || b%2==0 || c%2==0){
        cout << 0 << endl;
        return 0;
    }

    ll cut_edge = max(a, max(b, c));
    ll two, three;
    if(a == cut_edge){
        two = b;
        three = c;
    }
    if(b == cut_edge){
        two = c;
        three = a;
    }
    if(c == cut_edge){
        two = a;
        three = b;
    }

    cout << two*three << endl;
    
}