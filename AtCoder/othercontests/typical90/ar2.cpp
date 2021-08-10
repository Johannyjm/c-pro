#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    int shift = 0;
    for(int _ = 0; _ < q; ++_){
        int t, x, y;
        cin >> t >> x >> y;
        --x;
        --y;

        if(t == 1){
            int idx1 = (x - shift + n) % n;
            int idx2 = (y - shift + n) % n;

            swap(a[idx1], a[idx2]);
        }
        if(t == 2){
            ++shift;
        }
        if(t == 3){
            int idx = (x - shift + n) % n;
            cout << a[idx] << "\n";
        }
    }


    return 0;
}
