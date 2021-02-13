#include <iostream>
using namespace std;

bool is_prime(int num){
    if(num == 1) return false;

    for(int i = 2; i*i <= num; ++i){
        if(num%i == 0) return false;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int res = 0;
    for(int i = 1; i <= n; ++i){
        if(is_prime(i)) ++res;
    }
    
    cout << res << endl;

    return 0;
}
