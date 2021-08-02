#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;

    for(int i = 2; i*i <= n; ++i){
        if(n % i == 0){
            cout << i << " " << n / i << endl;
            return 0;
        }
    }
}