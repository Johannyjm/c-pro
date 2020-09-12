#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll base = 0;
    while((1ll<<base) <= n) ++base;
    --base;

    if(base%2 == 1){ // Takahashi last choice
        ll x = 1;
        for(int i = 0; i < base; ++i){
            if(i%2 == 0){ // Takahashi turn -> less choice
                x *= 2;
            }
            else x = x*2 + 1; // Aoki turn -> greater choice
        }

        if(x > n) cout << "Aoki" << endl;
        else cout << "Takahashi" << endl;
    }
    else{ // Aoki last choice
        ll x = 1;
        for(int i = 0; i < base; ++i){
            if(i%2 == 0){ // Takahashi turn -> greater choice
                x = x*2 + 1;
            }
            else x *= 2; // Aoki turn -> less choice
        }

        if(x > n) cout << "Takahashi" << endl;
        else cout << "Aoki" << endl;
    }

    
    return 0;
}
