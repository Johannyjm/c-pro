#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    string res = "";
    while(n){
        --n;
        res += char(n%26 + 'a');
        n /= 26;
    }

    reverse(res.begin(), res.end());
    
    cout << res << endl;

    return 0;
}
