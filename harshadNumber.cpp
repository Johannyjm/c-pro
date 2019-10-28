#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int n_tmp = N;
    int sum_digits = 0;

    while(n_tmp > 0){
        sum_digits += n_tmp % 10;
        n_tmp /= 10;
    }

    bool flg = N % sum_digits == 0;

    if(flg) cout << "Yes" << endl;
    else cout << "No" <<endl;
}