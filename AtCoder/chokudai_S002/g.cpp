#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int gcd(int a, int b){
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;

        cout << gcd(a, b) << endl;
    }

    return 0;
}
