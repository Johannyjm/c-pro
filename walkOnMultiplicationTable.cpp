#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll mina;
    ll minb;
    ll mind = N;

    for(int i = 1; i <= sqrt(N); ++i){

        if(N % i == 0){
            int d = N / 2 - i;
            
            if(d < mind){
                mina = i;
                minb = N / i;
            }
        }
    }
    cout << mina << " " << minb << endl;
    cout << mina + minb - 2 << endl;
}