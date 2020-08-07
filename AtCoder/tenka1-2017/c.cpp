#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    for(int a = 1; a <= 3500; ++a){
        for(int b = 1; b <= 3500; ++b){
            ll c1 = 4*a*b;
            ll c2 = n*b;
            ll c3 = n*a;
            ll c4 = n*a*b;

            if(c1-c2-c3==0){
                if(c4 == 0){
                    cout << a << " " << b << " " << 1 << endl;
                    return 0;
                }
                else continue;
            }
            else if(c1-c2-c3 < 0 || c1-c2-c3 > c4) continue;
            else{
                if(c4 % (c1-c2-c3) == 0){
                    ll c = c4 / (c1-c2-c3);
                    cout << a << " " << b << " " << c << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
