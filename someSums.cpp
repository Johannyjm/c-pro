#include <bits/stdc++.h>

using namespace std;

int findSomeOfDigits(int n){
    int sum = 0;

    while(n != 0){
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main(){
    int N, A, B;
    int res = 0;
    cin >> N >> A >> B;

    for(int n = 1; n <= N; ++n){
        int sums = findSomeOfDigits(n);
        //cout << sums << endl;
        if(A <= sums && sums <= B) res += n;
        //cout << n << sums << res << endl;
    }
    cout << res << endl;
}