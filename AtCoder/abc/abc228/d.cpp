#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n = 1 << 20;
    vector<ll> a(n, -1);
    vector<int> p(n, -1);

    int q;
    cin >> q;

    while(q--){
        ll t, x;
        cin >> t >> x;
        
        if(t == 1){
            int h = x%n;
            
            if(p[h] != -1) h = p[h];

            while(a[h] != -1){
                ++h;
                h %= n;
            }
            a[h] = x;
            p[x%n] = h;
        }
        if(t == 2){
            cout << a[x%n] << endl;
        }
    }

    return 0;
}
