#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    ll swp = 0;
    for(int i = 0; i < q; ++i){
        int t, x, y;
        cin >> t >> x >> y;

        x = (x-1+swp) % n;
        y = (y-1+swp) % n;
        
        if(t == 1){
            swap(a[x], a[y]);
        }
        if(t == 2){
            ++swp;
        }
        if(t == 3){
            cout << a[x] << "\n";
        }
    }

    return 0;
}
