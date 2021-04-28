#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b, c;
    cin >> a >> b >> c;

    ll bonc = 1;
    for(int i = 0; i < b; ++i) bonc *= c;
    if(a < bonc) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
