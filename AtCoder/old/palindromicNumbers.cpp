#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;

    int res = 0;

    for(int num = A; num <= B; ++num){
        int digits[5];
        int num_tmp = num;

        for(int i = 0; i < 5; ++i){
            digits[i] = num_tmp % 10;
            num_tmp /= 10;
        }
        if(digits[0] == digits[4] and digits[1] == digits[3]) res++;
    }

    cout << res << endl;
}