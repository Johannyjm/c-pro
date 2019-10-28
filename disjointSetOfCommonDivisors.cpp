#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(ll a, ll b) { 
   
   if (b == 0) 
      return a; 
   
   return gcd(b, a % b);  
} 

bool isPrime(ll num){

    if(num < 2) return false;
    if(num == 2) return true;
    if(num % 2 == 0) return false;
    else if(num > 2){

        for (ll j = 3; j * j < num; j += 2){

            if(num % j == 0) return false;
        }
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll A, B;
    cin >> A >> B;
    ll N = gcd(A, B);
    ll res = 0;

    for(ll i = 1; (i - 1) * (i - 1) <= N; ++i){

        if(A % i == 0 and B % i == 0){
            
            if(isPrime(i)) res++;
        }
    }
    cout << res + 1 << endl;
}